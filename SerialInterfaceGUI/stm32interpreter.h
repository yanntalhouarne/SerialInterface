#ifndef STM32INTERPRETER_H
#define STM32INTERPRETER_H

#include <QObject>
#include <QWidget>
#include <QByteArray>
#include <QSerialPort>
#include <QTimer>
#include <QEventLoop>
#include <QThread>

QT_BEGIN_NAMESPACE


#include "console.h"
#include "stm32bootloaderdialog.h"
#include "progressbardialog.h"

#define INIT_CMD 0x7F
#define GET_CMD 0x00
#define GET_VERSION_AND_READ_PROTECTION_CMD 0x01
#define GET_ID_CMD 0x02
#define READ_MEMORY_CMD 0x11
#define GO_CMD 0x21
#define WRITE_MEMORY_CMD 0x31
#define ERASE_CMD 0x44
#define EXTENDED_ERASE_GET_CMD 0x44
#define WRITE_PROTECT_CMD 0x63
#define WRITE_UNPROTECT_CMD 0x73
#define READOUT_PROTECT_CMD 0x82
#define READOUT_UNPROTECT_CMD 0x92

// CUSTOM CMDS
#define UPDATE_FW_CMD 0x99
#define GLOBAL_ERASE_CMD 0x98

#define STM32_ACK 0x79
#define STM32_NACK 0x1F
#define STM32_BUSY 0x76
#define STM32_TIMEOUT 0x12
#define STM32_UNKNOWN 0x20
#define ACK_TIMEOUT 1000


class stm32Interpreter : public QWidget
{
    Q_OBJECT

public:
    stm32Interpreter();

    void sendCmd(QSerialPort * serialPort, unsigned char cmd);

    bool parseCmd(char cmd, stm32bootloaderDialog::hexFileSettings hexSettings, QSerialPort * serialPort, Console * csl);

    unsigned char getCmdSent();

    bool writeMemory(QSerialPort * serialPort, Console * csl, long address, const QByteArray data, unsigned int len);

    bool updateFirmware(QSerialPort * serialPort, Console * csl, long address, const QByteArray data, unsigned int len);

    //void  setTimeoutFlag();

    bool globalErase(QSerialPort * serialPort, Console * csl);

    char waitForACK(QSerialPort * serialPort, Console * csl, unsigned int timeout_ms);

    bool getPID(QSerialPort * serialPort, Console * csl);

    bool initDevice(QSerialPort * serialPort, Console * csl);

private:
    //bool acknowledgment = 0;
    unsigned char cmdSent = 0;
    //QTimer * timer = nullptr;
    //bool timeout = 0;
    QByteArray hexFileData;
    stm32bootloaderDialog::hexFileSettings m_hexFileSettings;
    progressBarDialog * m_progressBarDialog = nullptr;
    QEventLoop * m_eventLoop = nullptr;

};


#endif // STM32INTERPRETER_H
