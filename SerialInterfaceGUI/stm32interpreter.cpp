#include "stm32interpreter.h"


stm32Interpreter::stm32Interpreter()
{
    //timer = new QTimer(this);
    //connect(timer, &QTimer::timeout, this, &stm32Interpreter::setTimeoutFlag);
    m_progressBarDialog = new progressBarDialog(this);
    m_eventLoop = new QEventLoop(this);
}

unsigned char stm32Interpreter::getCmdSent()
{
    return cmdSent;
}

bool stm32Interpreter::writeMemory(QSerialPort * serialPort, Console * csl, long address, const QByteArray data, unsigned int len)
{
    uint32_t addr = (uint32_t)address;
    QByteArray baBuffer;
    uint8_t cs, buf[256 + 2];
    unsigned int i, aligned_len;

    if (!len)
    {
        csl->putData("Error: Data length cannot be 0.");
        return 0;
    }

    if (len > 256)
    {
        csl->putData("Error: Data length limit at 256 bytes\n");
        return 0;
    }

    /* must be 32bit aligned */
    if (addr & 0x3 || len & 0x3)
    {
        csl->putData("Error: WRITE address and data length must be 4 byte aligned\n");
        return 0;
    }

/* SEND COMMAND */
    /* send the command and checksum */
    baBuffer.append(WRITE_MEMORY_CMD);
    baBuffer.append((char)(WRITE_MEMORY_CMD ^ 0xFF));
    serialPort->write(baBuffer);
    baBuffer.clear();
//    baBuffer.append("WR MEM: ");
//    baBuffer.append(13);
//    baBuffer.append("   SEND CMD:");
//    baBuffer.append(13);
//    csl->putData(baBuffer);
//    baBuffer.clear();
    /* WAIT FOR ACK */
    if(waitForACK(serialPort, csl, 1000) != STM32_ACK)
        return 0;


/* SEND ADDRESS */
    /* get address into tx buffer */
    buf[0] = addr >> 24;
    buf[1] = (addr >> 16) & 0xFF;
    buf[2] = (addr >> 8) & 0xFF;
    buf[3] = addr & 0xFF;
    buf[4] = buf[0] ^ buf[1] ^ buf[2] ^ buf[3];
    for (int i = 0; i < 5; i++)
        baBuffer.append(buf[i]);
    serialPort->write(baBuffer);
    baBuffer.clear();
//    baBuffer.append("   SEND ADRR:");
//    baBuffer.append(13);
//    csl->putData(baBuffer);
//    baBuffer.clear();
    /* WAIT FOR ACK */
    if(waitForACK(serialPort, csl, 30000) != STM32_ACK)
        return 0;

/* SEND NUMBER OF BYTES + DATA */
    aligned_len = (len + 3) & ~3;
    cs = aligned_len - 1;
    /* number of bytes to be received */
    buf[0] = aligned_len - 1;
    /* data */
    for (i = 0; i < len; i++) {
        cs ^= data[i];
        buf[i + 1] = data[i];
    }
    /* padding data */
    for (i = len; i < aligned_len; i++) {
        cs ^= 0xFF;
        buf[i + 1] = 0xFF;
    }
    /* checksum */
    buf[aligned_len + 1] = cs;

    for (i = 0; i < aligned_len + 2; i++)
    {
        baBuffer.append(buf[i]);
    }
    serialPort->write(baBuffer);
    baBuffer.clear();
//    baBuffer.append("   SEND DATA:");
//    baBuffer.append(13);
//    csl->putData(baBuffer);
//    baBuffer.clear();
    /* WAIT FOR ACK */
    if(waitForACK(serialPort, csl, 30000) != STM32_ACK)
        return 0;

    return 1;
}

bool stm32Interpreter::updateFirmware(QSerialPort * serialPort, Console * csl, long address, const QByteArray data, unsigned int len)
{
    long temp_addr = address;
    QByteArray temp_data;
    unsigned int remaining_len = len;
    unsigned int offset = 0;
    unsigned int nbr_pages_written = 0;

    m_progressBarDialog->setModal(1);

    m_progressBarDialog->setProgressBarRange(len);

    m_progressBarDialog->setProgressBarValue(0);

    if (!globalErase(serialPort, csl))
    {
        m_progressBarDialog->setLabel("Could not erase flash memory.\n");
        return 0;
    }

    m_progressBarDialog->setLabel("Updating firmware...\n");
    m_progressBarDialog->show();

    m_progressBarDialog->enableAbortButton();
    m_progressBarDialog->disableDoneButton();

    bool writeSuccess = 1;
    csl->putData("UPDATE FIRMWARE:\n");
    /* WRITE BIN FILE TO FLASH MEMORY */
    while ((remaining_len > 256)&&(writeSuccess)&&(!m_progressBarDialog->getAbortFlag()))
    {
        double percentage = 100 - (double)((double)remaining_len/(double)len)*100;
        QString strAscii = QString::number((int)percentage, 10);
        QByteArray baAscii = strAscii.toUtf8();
        baAscii.append('%');
        baAscii.append(13);
        csl->putData(baAscii);
        m_progressBarDialog->setProgressBarValue(len-remaining_len);
        // update temp data buffer
        temp_data.clear();
        for (unsigned int i = offset; i < offset+256; i++)
        {
            if (!data.isEmpty())
             temp_data.append(data[i]);
        }

        if (!writeMemory(serialPort, csl, temp_addr, temp_data, 256))
        {
            writeSuccess = 0;
        }
        else
        {
            nbr_pages_written++;
        }

        temp_addr += 256;
        offset += 256;
        remaining_len -= 256;
    }
    temp_data.clear();
    if ((remaining_len > 0) && (writeSuccess) && (!m_progressBarDialog->getAbortFlag()))
    {
        m_progressBarDialog->setProgressBarValue(len-remaining_len);
        for (unsigned int i = offset; i < offset+remaining_len; i++)
        {
            temp_data.append(data[i]);
        }
        if (!writeMemory(serialPort, csl, temp_addr, temp_data, remaining_len))
        {
            writeSuccess = 0;
        }
        else
        {
            nbr_pages_written++;
            csl->putData("100%\n");
        }
    }

    csl->putData("Number of pages written: ");
    QString strAscii = QString::number(nbr_pages_written);
    QByteArray baAscii = strAscii.toUtf8();
    baAscii.append(13);
    csl->putData(baAscii);

    if (writeSuccess && (!m_progressBarDialog->getAbortFlag()))
    {
        m_progressBarDialog->setProgressBarValue(len);
        m_progressBarDialog->setLabel("Firmware update successful!\n");
    }  
    else
    {
        m_progressBarDialog->setLabel("Firmware update failed.\n");
    }

    m_progressBarDialog->clearAbortFlag();
    m_progressBarDialog->disableAbortButton();
    m_progressBarDialog->enableDoneButton();

    return writeSuccess;
}

bool stm32Interpreter::globalErase(QSerialPort * serialPort, Console * csl)
{
        QByteArray baBuffer;

    /* SEND COMMAND */
        /* send the command and checksum */
        baBuffer.append(ERASE_CMD);
        baBuffer.append((unsigned char)(ERASE_CMD ^ 0xFF)); // should be 0xBC
        serialPort->write(baBuffer);
        baBuffer.clear();
        baBuffer.append("ERASE MEMORY: ");
        baBuffer.append(13);
        csl->putData(baBuffer);
        baBuffer.clear();

    /* WAIT FOR ACK */
        if (waitForACK(serialPort, csl, 1000) != STM32_ACK)
            return 0;

    /* SEND GLOBAL ERASE COMMAND */
        baBuffer.append((char)0x00);
        baBuffer.append((char)0x04);
        baBuffer.append((char)0x00);
        baBuffer.append((char)0x00);
        baBuffer.append((char)0x00);
        baBuffer.append((char)0x01);
        baBuffer.append((char)0x00);
        baBuffer.append((char)0x02);
        baBuffer.append((char)0x00);
        baBuffer.append((char)0x03);
        baBuffer.append((char)0x00);
        baBuffer.append((char)0x04);
        baBuffer.append((char)0x00);
        serialPort->write(baBuffer);
        baBuffer.clear();

    /* WAIT FOR ACK */
        if (waitForACK(serialPort, csl, 5000) != STM32_ACK)
            return 0;

        return 1;
}

char stm32Interpreter::waitForACK(QSerialPort * serialPort, Console * csl, unsigned int timeout_ms)
{
    QByteArray baBuffer;
    char returnVal = 0;

    if(!serialPort->waitForReadyRead(timeout_ms))
    {
        /* print timeout to console */
        returnVal = STM32_TIMEOUT;
        baBuffer.append("       -timeout");
    }
    else
    {
        /* print device response to console */
        const QByteArray rxData = serialPort->readAll();
        if (rxData[0] == STM32_ACK)
        {
            returnVal = rxData[0];
            baBuffer.append("       -ACK");
        }
        else if (rxData[0] == STM32_NACK)
        {
            returnVal = rxData[0];
            baBuffer.append("       -NACK");
        }
        else if (rxData[0] == STM32_BUSY)
        {
            returnVal = rxData[0];
            baBuffer.append("       -BUSY");
        }
        else
        {
            returnVal = STM32_UNKNOWN;
            baBuffer.append("       -unknown");
        }
    }
    /* print ACK/timeout to console */
    baBuffer.append(13); // add CR character
    csl->putData(baBuffer); // print to console
    baBuffer.clear();

     m_eventLoop->processEvents(QEventLoop::AllEvents);
     QThread::msleep(10);

    return returnVal;
}

bool stm32Interpreter::getPID(QSerialPort * serialPort, Console * csl)
{
    QByteArray baBuffer;
    bool resultVal = false;

    /* SEND COMMAND */
    baBuffer.append(GET_ID_CMD);
    baBuffer.append((char)(GET_ID_CMD ^ 0xFF));
    serialPort->write(baBuffer);
    baBuffer.clear();

    /* GET RESPONSE */
    int data = 0;
    QString tempChar;
    baBuffer.append("GET_ID: ");
    baBuffer.append(13);
    if(!serialPort->waitForReadyRead(1000))
    {
        /* print timeout to console */
        baBuffer.append("       -timeout");
        baBuffer.append(13);
    }
    else
    {
        const QByteArray rxData = serialPort->readAll();
        if (rxData.size() >= 5)
        {
            if (rxData[0] == STM32_ACK)
            {
                baBuffer.append("   -N = ");
                tempChar = QString::number((int)rxData[1]);
                baBuffer.append(tempChar);
                baBuffer.append(13);
                baBuffer.append("   -PID = ");
                data = ((0x000000FF)&(rxData[3])) | ((0x0000FF00)&(rxData[2]<<8));
                tempChar.clear();
                tempChar = QString::number(data);
                baBuffer.append(tempChar);
                baBuffer.append(13);
                if (rxData[4] == STM32_ACK)
                    resultVal = true;
            } // end of: if (rxData[0] == ACK)          
        }
        else
        {
            if (rxData[0] == STM32_NACK)
            {
                baBuffer.append("   -NACK");
            }
            else if (rxData[0] == STM32_BUSY)
            {
                baBuffer.append("   -BUSY");
            }
            else
            {
                 baBuffer.append("   -UNKNOWN");
            }
        }
    }

    baBuffer.append(13);
    csl->putData(baBuffer);
    baBuffer.clear();

    return resultVal;
}

bool stm32Interpreter::initDevice(QSerialPort * serialPort, Console * csl)
{
    QByteArray baBuffer;

/* SEND CMD */
    baBuffer.append(INIT_CMD);
    serialPort->write(baBuffer);
    baBuffer.clear();
    baBuffer.append("INIT DEVICE: ");
    baBuffer.append(13);
    csl->putData(baBuffer);
    baBuffer.clear();
/* WAIT FOR ACK */
    if (waitForACK(serialPort, csl, 1000) != STM32_ACK)
        return false;

    return true;
}

bool stm32Interpreter::parseCmd(char cmd, stm32bootloaderDialog::hexFileSettings hexSettings, QSerialPort * serialPort, Console * csl)
{
    bool returnVal = false;

    switch ((unsigned char)cmd)
    {
        case GLOBAL_ERASE_CMD:
        {
            returnVal = globalErase(serialPort, csl);
            break;
        }
        case INIT_CMD:
        {
            returnVal = initDevice(serialPort, csl);
            break;
        }
        case UPDATE_FW_CMD:
        {
            if (hexSettings.fileOpened)
                returnVal = updateFirmware(serialPort, csl, hexSettings.adrress, hexSettings.getDataFromHexFile(), hexSettings.length);
            else
                csl->putData("No file is selected.\n");
            break;
        }
        case GET_ID_CMD:
        {
            returnVal = getPID(serialPort, csl);
            break;
        }
        default:
        {
            csl->putData("Command invalid, or not supported.");
            break;
        }
    }

    return returnVal;
}
