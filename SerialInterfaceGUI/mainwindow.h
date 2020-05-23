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

/* MY CLASSES */
#include "console.h"
#include "serialportsettings.h"


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
    void processData();
    void connectToPort();
    void disconnectToPort();
    void clearTextEdit();
    void changeScrolling();
    void refreshPortList();

private:
    Ui::MainWindow * ui;
    //Console * m_console = nullptr;
    QSerialPort * m_serial = nullptr;
    serialPortSettingsDialog * m_settings = nullptr;
};
#endif // MAINWINDOW_H


