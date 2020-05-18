#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/* QT API CLASSES */
#include <QMainWindow>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>

/* MY CLASSES */
#include "slavethread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startSlave();
    void processError(const QString &s);
    void processTimeout(const QString &s);
    void processData(QByteArray dataArray);

private:
    Ui::MainWindow *ui;

    int m_transactionCount = 0;

    QLabel * m_comStatusLabel = nullptr; // Not connected, Connected or Failed
    QLabel * m_comPortLabel = nullptr; // "Serial port:"
    QLabel * m_rxDataLabel = nullptr; //  "RX data:"
    QComboBox * m_serialPortComboBox = nullptr; // drop-down list of all the available ports
    QPushButton * m_refreshButton = nullptr; //  update the COM PORT drop-down list
    QPushButton * m_connectButton = nullptr; //  conect to the selected port and start receiving data (calls run())
    QLineEdit * m_rxDataLineEdit = nullptr;

    QByteArray rxData; // array of bytes holding data received on port

    SlaveThread m_thread; // instance of our SlaveThreads, which continously reads data from the serialPORT
};
#endif // MAINWINDOW_H


