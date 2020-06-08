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
#include <QSpinBox>
#include <QAction>


/* MY CLASSES */
#include "console.h"
#include "serialportsettings.h"
#include "serialparsingsettingsdialog.h"
#include "loggingsettingsdialog.h"
#include "portconnfailuredialog.h"
#include "stm32interpreter.h"
#include "stm32bootloaderdialog.h"

/* THIRD PARTY */
#include "qcustomplot.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /* PLOTING */
    void addPoint(double x, double y);
    void clearData();
    void plot();
    bool didLoggingStart();
    bool isConnected();

private slots:
    void processData();
    void connectToPort();
    void disconnectToPort();
    void clearTextEdit();
    void changeScrolling();
    void refreshPortList();
    void changeAxisRange_X(int val);
    void changeLowerAxisRange_Y(int val);
    void changeUpperAxisRange_Y(int val);
    void changeAxisAutoRange();
    void stopLogging();
    void startLogging();
    void checkLogEnabledFlag();
    void sendToPort();
    void updateParsingSettings();

private:
    Ui::MainWindow * ui;
    QSerialPort * m_serial = nullptr;
    serialPortSettingsDialog * m_settings = nullptr;
    serialParsingSettingsDialog * m_parsingSettingsDialog = nullptr;
    PortConnFailureDialog * m_portConnFailureDialog = nullptr;
    LoggingSettingsDialog * m_loggingSettingsDialog = nullptr;
    stm32bootloaderDialog * m_stm32bootloaderDialog = nullptr;
    QVector<double> qv_x, qv_y; // for plotting
    bool startedLoggingToFile = 0;
    bool connectedToPort = 0;
    int xAxisRange = 100;
    int yAxisLower = -100;
    int yAxisUpper = 100;
    int yAxisRange = yAxisUpper-yAxisLower;
    stm32Interpreter m_stm32Interpreter;

};
#endif // MAINWINDOW_H


