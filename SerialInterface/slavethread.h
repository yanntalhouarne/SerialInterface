#ifndef SLAVETHREAD_H
#define SLAVETHREAD_H

#include <QObject>
#include <QMutex>
#include <QThread>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QTime>

class SlaveThread : public QThread
{
    Q_OBJECT

public:
    explicit SlaveThread(QObject *parent = nullptr);
    ~SlaveThread();

    void startSlave(const QString &portName, int waitTimeout);

signals:
    // void request(const QString &s); // used to request data from MainWindow to be transmitted to the PORT
    void error(const QString &s);
    void timeout(const QString &s);
    void data(QByteArray dataArray); // send a copy of the byte array we received on the COM port

private:
    void run() override;

    QString m_portName;
    int m_waitTimeout = 0;
    QMutex m_mutex;
    bool m_quit = false;
};

#endif // SLAVETHREAD_H
