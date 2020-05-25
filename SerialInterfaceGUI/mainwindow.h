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

private slots:
    void processData();
    void connectToPort();
    void disconnectToPort();
    void clearTextEdit();
    void changeScrolling();
    void refreshPortList();

private:
    Ui::MainWindow * ui;
    QSerialPort * m_serial = nullptr;
    serialPortSettingsDialog * m_settings = nullptr;
    QVector<double> qv_x, qv_y; // for plotting

};
#endif // MAINWINDOW_H


