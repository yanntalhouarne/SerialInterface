#include "stm32interpreter.h"


stm32Interpreter::stm32Interpreter()
{
    //timer = new QTimer(this);
    //connect(timer, &QTimer::timeout, this, &stm32Interpreter::setTimeoutFlag);
}

void stm32Interpreter::sendCmd(QSerialPort * serialPort, unsigned char cmd)
{
    QByteArray baBuffer;

    // update the command indicator
    cmdSent = cmd;

    switch (cmd)
    {
        case INIT_CMD:
        {
            baBuffer.append(INIT_CMD);
            serialPort->write(baBuffer);
            baBuffer.clear();
            break;
        }
        case GET_CMD:
        {

            break;
        }
        case GET_VERSION_AND_READ_PROTECTION_CMD:
        {

            break;
        }
        case GET_ID_CMD:
        {
            baBuffer.append(GET_ID_CMD);
            baBuffer.append((char)(GET_ID_CMD ^ 0xFF));
            serialPort->write(baBuffer);
            baBuffer.clear();
            break;
        }
        case READ_MEMORY_CMD:
        {

            break;
        }
//        case GO_CMD:
//        {

//            break;
//        }
        case WRITE_MEMORY_CMD:
        {

            break;
        }
        case ERASE_CMD:
        {

            break;
        }
        case EXTENDED_ERASE_GET_CMD:
        {

            break;
        }
        case WRITE_PROTECT_CMD:
        {

            break;
        }
        case WRTIE_UNPROTECT_CMD:
        {

            break;
        }
        case READOUT_PROTECT_CMD:
        {

            break;
        }
        case READOUT_UNPROTECT_CMD:
        {

            break;
        }
        default:
            break;
    } // end of: switch (cmd)
}



bool stm32Interpreter::parseCmd(Console * csl, const QByteArray rxData)
{
    QByteArray rxByteArray;

    acknowledgment = 0;

    switch (cmdSent)
    {
        case INIT_CMD:
        {
            rxByteArray.append("INIT: ");
            if (rxData[0] == STM32_ACK)
            {
                acknowledgment = 1;
                rxByteArray.append("ACK");
            }
            else if (rxData[0] == STM32_NACK)
            {
                rxByteArray.append("NACK");
            }
            else if (rxData[0] == STM32_BUSY)
            {
                rxByteArray.append("BUSY");
            }
            else
            {
                rxByteArray.append("unknown");
            }
            rxByteArray.append(13);
            csl->putData(rxByteArray);
            rxByteArray.clear();
            break;
        }
        case GET_CMD:
        {

            break;
        }
        case GET_VERSION_AND_READ_PROTECTION_CMD:
        {

            break;
        }
        case GET_ID_CMD:
        {
            int data = 0;
            QString tempChar;
            rxByteArray.append("GET_ID: ");
            if (rxData.size() >= 4)
            {
                if (rxData[0] == STM32_ACK)
                {
                    rxByteArray.append("N = ");
                    tempChar = QString::number((int)rxData[1]);
                    rxByteArray.append(tempChar);
                    rxByteArray.append(", PID = ");
                    data = ((0x000000FF)&(rxData[3])) | ((0x0000FF00)&(rxData[2]<<8));
                    tempChar.clear();
                    tempChar = QString::number(data);
                    rxByteArray.append(tempChar);
                    if (rxData[4] == STM32_ACK)
                        acknowledgment = 1;
                } // end of: if (rxData[0] == ACK)

                if (acknowledgment != 1)
                {
                    rxByteArray.append("NACK");
                }

                rxByteArray.append(13);
                csl->putData(rxByteArray);
                rxByteArray.clear();
            }
            break;
        }
        case READ_MEMORY_CMD:
        {

            break;
        }
        case GO_CMD:
        {

            break;
        }
        case WRITE_MEMORY_CMD:
        {

            break;
        }
        case ERASE_CMD:
        {

            break;
        }
        case EXTENDED_ERASE_GET_CMD:
        {

            break;
        }
        case WRITE_PROTECT_CMD:
        {

            break;
        }
        case WRTIE_UNPROTECT_CMD:
        {

            break;
        }
        case READOUT_PROTECT_CMD:
        {

            break;
        }
        case READOUT_UNPROTECT_CMD:
        {

            break;
        }
        default:
            break;
    } // end of: switch (cmd)

    return acknowledgment;
}

bool stm32Interpreter::getAcknowledgment()
{
    return acknowledgment;
}
unsigned char stm32Interpreter::getCmdSent()
{
    return cmdSent;
}



bool stm32Interpreter::writeMemory(QSerialPort * serialPort, Console * csl, long address, const QByteArray data, unsigned int len)
{
    uint32_t addr = (uint32_t)address;
    acknowledgment = 0;
    timeout = 0;
    QByteArray baBuffer;
    uint8_t cs, buf[256 + 2];
    unsigned int i, aligned_len;

    if (!len)
        return STM32_ERR_OK;

    if (len > 256) {
        fprintf(stderr, "Error: READ length limit at 256 bytes\n");
        //return STM32_ERR_UNKNOWN;
    }

    /* must be 32bit aligned */
    if (addr & 0x3 || len & 0x3) {
        fprintf(stderr, "Error: WRITE address and length must be 4 byte aligned\n");
        //return STM32_ERR_UNKNOWN;
    }

/* SEND COMMAND */
    /* send the command and checksum */
    baBuffer.append(WRITE_MEMORY_CMD);
    baBuffer.append((char)(WRITE_MEMORY_CMD ^ 0xFF));
    serialPort->write(baBuffer);
    baBuffer.clear();

    /* get ACK from device */
    baBuffer.append("WR MEM: ");
    baBuffer.append(13);
    baBuffer.append("   SEND CMD:");
    baBuffer.append(13);
    if(!serialPort->waitForReadyRead(1000))
    {
        /* print timeout to console */
        timeout = 1;
        baBuffer.append("       -timeout");
    }
    else
    {
        /* print device response to console */
        const QByteArray rxData = serialPort->readAll();
        if (rxData[0] == STM32_ACK)
        {
            acknowledgment = 1;
            baBuffer.append("       -ACK");
        }
        else if (rxData[0] == STM32_NACK)
            baBuffer.append("       -NACK");
        else if (rxData[0] == STM32_BUSY)
            baBuffer.append("       -BUSY");
        else
            baBuffer.append("       -unknown");
    }
    /* print ACK/timeout to console */
    baBuffer.append(13); // add CR character
    csl->putData(baBuffer); // print to console
    baBuffer.clear();
    acknowledgment = 0;
    timeout = 0;


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

    /* wait for ACK */
    baBuffer.append("   SEND ADRR:");
    baBuffer.append(13);
    if(!serialPort->waitForReadyRead(1000))
    {
        /* print timeout to console */
        timeout = 1;
        baBuffer.append("       -timeout");
    }
    else
    {
        /* print device response to console */
        const QByteArray rxData = serialPort->readAll();
        if (rxData[0] == STM32_ACK)
        {
            acknowledgment = 1;
            baBuffer.append("       -ACK");
        }
        else if (rxData[0] == STM32_NACK)
            baBuffer.append("       -NACK");
        else if (rxData[0] == STM32_BUSY)
            baBuffer.append("       -BUSY");
        else
            baBuffer.append("       -unknown");
    }
    csl->putData(baBuffer);
    baBuffer.clear();
    acknowledgment = 0;
    timeout = 0;


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


    /* wait for ACK */
    baBuffer.append("   SEND DATA:");
    baBuffer.append(13);
    if(!serialPort->waitForReadyRead(1000))
    {
        /* print timeout to console */
        timeout = 1;
        baBuffer.append("       -timeout");
    }
    else
    {
        /* print device response to console */
        const QByteArray rxData = serialPort->readAll();
        if (rxData[0] == STM32_ACK)
        {
            acknowledgment = 1;
            baBuffer.append("       -ACK");
        }
        else if (rxData[0] == STM32_NACK)
            baBuffer.append("       -NACK");
        else if (rxData[0] == STM32_BUSY)
            baBuffer.append("       -BUSY");
        else
            baBuffer.append("       -unknown");
    }
    csl->putData(baBuffer);
    baBuffer.clear();


    return acknowledgment | timeout;
}

bool stm32Interpreter::updateFirmware(QSerialPort * serialPort, Console * csl, long address, const QByteArray data, unsigned int len)
{
    long temp_addr = address;
    QByteArray temp_data;
    unsigned int remaining_len = len;
    unsigned int offset = 0;

    bool writeSuccess = 1;

    while ((remaining_len > 256)&&(writeSuccess))
    {
        // update temp data buffer
        temp_data.clear();
        for (unsigned int i = offset; i < offset+256; i++)
        {
            if (!data.isEmpty())
             temp_data.append(data[i]);
        }

        if (writeMemory(serialPort, csl, temp_addr, temp_data, 256))
        {
            //writeSuccess = 0;
        }

        temp_addr += 256;
        offset += 256;
        remaining_len -= 256;
    }

    return writeSuccess;
}

//void stm32Interpreter::setTimeoutFlag()
//{
//    timeout = 1;
//}

