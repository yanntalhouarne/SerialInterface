#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/* QT API CLASSES */
#include <QMainWindow>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QTextEdit>
#include <QChar>
#include <QDebug>
#include <QObject>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QTime>
#include <QScrollBar>
#include <QPlainTextEdit>
#include <QCheckBox>


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
    void processTimeout(const QString &s);
    void processData();
    void connectToPort();
    void disconnectToPort();
    void clearTextEdit();
    void changeScrolling();

private:
    Ui::MainWindow *ui;

    int m_transactionCount = 0;

    QLabel * m_comStatusLabel = nullptr; // Not connected, Connected or Failed
    QLabel * m_comPortLabel = nullptr; // "Serial port:"
    QLabel * m_rxDataLabel = nullptr; //  "RX data:"
    QComboBox * m_serialPortComboBox = nullptr; // drop-down list of all the available ports
    QPushButton * m_disconnectButton = nullptr; //  disconnect from the port
    QPushButton * m_connectButton = nullptr; //  conect to the selected port and start receiving data (calls run())
    QPushButton * m_clearTextButton = nullptr;
    QPlainTextEdit * m_rxDataPlainTextEdit = nullptr;
    QScrollBar * m_bar = nullptr;
    QSerialPort * m_serial = nullptr;
    QCheckBox * m_autoscrollCheckBox = nullptr;
    bool autoScroll = 1;

};
#endif // MAINWINDOW_H


