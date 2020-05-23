#ifndef SERIALPORTSETTINGS_H
#define SERIALPORTSETTINGS_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QPushButton>

QT_BEGIN_NAMESPACE

namespace Ui {class portSettingsDialog;}

class serialPortSettingsDialog : public QDialog
{

    Q_OBJECT

public:
    serialPortSettingsDialog(QWidget *parent = nullptr);
    ~serialPortSettingsDialog();


public:
    struct Settings {
        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;
     //   bool localEchoEnabled;
    };

    Settings settings() const;



private slots:
    void showPortInfo(int idx);
    void apply();


private:
    Ui::portSettingsDialog * ui = nullptr;
    void updateSettings();
    void fillPortsParameters();
    void fillPortsInfo();
    Settings m_currentSettings;

public:
    QString getCurrentName();
    qint32 getCurrentBaudRate();
    QSerialPort::DataBits getCurrentDatabits();
    QSerialPort::Parity getCurrentParity();
    QSerialPort::StopBits getCurrentStopBits();
    QSerialPort::FlowControl getCurrentFLowControl();
    void setDefault();
    void setPort(QString portName);

};

#endif // SERIALPORTSETTINGS_H
