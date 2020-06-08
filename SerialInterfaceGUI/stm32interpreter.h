#ifndef STM32INTERPRETER_H
#define STM32INTERPRETER_H

#include <QObject>
#include <QWidget>
#include <QByteArray>
#include <QSerialPort>
#include <QTimer>

QT_BEGIN_NAMESPACE


#include "console.h"
#include "stm32bootloaderdialog.h"

#define INIT_CMD 0x7F
#define GET_CMD 0x00
#define GET_VERSION_AND_READ_PROTECTION_CMD 0x01
#define GET_ID_CMD 0x02
#define READ_MEMORY_CMD 0x11
#define GO_CMD 0x21
#define WRITE_MEMORY_CMD 0x31
#define ERASE_CMD 0x43
#define EXTENDED_ERASE_GET_CMD 0x44
#define WRITE_PROTECT_CMD 0x63
#define WRTIE_UNPROTECT_CMD 0x73
#define READOUT_PROTECT_CMD 0x82
#define READOUT_UNPROTECT_CMD 0x92

#define STM32_ACK 0x79
#define STM32_NACK 0x1F
#define STM32_BUSY 0x76
#define STM32_ERR_OK 0x00


class stm32Interpreter : public QWidget
{
    Q_OBJECT

public:
    stm32Interpreter();

    void sendCmd(QSerialPort * serialPort, unsigned char cmd);

    bool parseCmd(Console * csl, const QByteArray rxData);

    bool getAcknowledgment();
    unsigned char getCmdSent();

    bool writeMemory(QSerialPort * serialPort, Console * csl, long address, const QByteArray data, unsigned int len);

    bool updateFirmware(QSerialPort * serialPort, Console * csl, long address, const QByteArray data, unsigned int len);

    void  setTimeoutFlag();


private:
    bool acknowledgment = 0;
    unsigned char cmdSent = 0;
    //QTimer * timer = nullptr;
    bool timeout = 0;
    QByteArray hexFileData;
    stm32bootloaderDialog::hexFileSettings m_hexFileSettings;
};


#endif // STM32INTERPRETER_H
