/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "console.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect;
    QAction *actionRefresh;
    QAction *actionDisconnect;
    QAction *actionClear;
    QAction *actionToggle_Auto_Scroll;
    QAction *actionConfigure;
    QAction *actionConfigurePort;
    QAction *actionParsing;
    QAction *actionStart_logging;
    QAction *actionStop_logging;
    QAction *actionConfigure_logging;
    QAction *actionBootloaderConfigure;
    QAction *actionBootloaderInfo;
    QWidget *centralwidget;
    QWidget *TerminalWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *DisconnectButton;
    QVBoxLayout *verticalLayout;
    QPushButton *ConnectButton;
    QPushButton *RefreshButton;
    QComboBox *term_comboBox;
    QLabel *term_comboBoxLabel;
    QWidget *ConsoleWidget;
    Console *m_console;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QCheckBox *printCheckBox;
    QCheckBox *autoscroll;
    QLabel *label;
    QSpinBox *rowNbrSpinBox;
    QLabel *parsingLabel;
    QPushButton *clearButton;
    QWidget *plotWidget;
    QCustomPlot *plot;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *xAxisRangeLabel;
    QCheckBox *xAxisAutoRangeCheckbox;
    QSpinBox *xAxisRangeSpinbox;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *plotCheckBox;
    QPushButton *clearPlot;
    QLabel *yAxisLowerLabel;
    QLabel *yAxisUpperLabel;
    QLabel *consoleStatusLabel;
    QTextEdit *txConsoleTextEdit;
    QLabel *txLabel;
    QPushButton *sendButton;
    QCheckBox *crCheckBox;
    QCheckBox *lfCheckBox;
    QCheckBox *asciiFormatCheckbox;
    QFrame *frame_3;
    QFrame *frame;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *yAxisRangeLabel;
    QCheckBox *yAxisAutoRangeCheckbox;
    QSpinBox *yAxisLowerSpinbox;
    QSpinBox *yAxisUpperSpinbox;
    QMenuBar *menubar;
    QMenu *menuPort;
    QMenu *menuConsole;
    QMenu *menuLogs;
    QMenu *menuSTM32_Bootloader;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1159, 604);
        MainWindow->setMinimumSize(QSize(1152, 604));
        MainWindow->setAutoFillBackground(false);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        actionRefresh = new QAction(MainWindow);
        actionRefresh->setObjectName(QString::fromUtf8("actionRefresh"));
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        actionToggle_Auto_Scroll = new QAction(MainWindow);
        actionToggle_Auto_Scroll->setObjectName(QString::fromUtf8("actionToggle_Auto_Scroll"));
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QString::fromUtf8("actionConfigure"));
        actionConfigurePort = new QAction(MainWindow);
        actionConfigurePort->setObjectName(QString::fromUtf8("actionConfigurePort"));
        actionParsing = new QAction(MainWindow);
        actionParsing->setObjectName(QString::fromUtf8("actionParsing"));
        actionParsing->setEnabled(true);
        actionStart_logging = new QAction(MainWindow);
        actionStart_logging->setObjectName(QString::fromUtf8("actionStart_logging"));
        actionStop_logging = new QAction(MainWindow);
        actionStop_logging->setObjectName(QString::fromUtf8("actionStop_logging"));
        actionConfigure_logging = new QAction(MainWindow);
        actionConfigure_logging->setObjectName(QString::fromUtf8("actionConfigure_logging"));
        actionBootloaderConfigure = new QAction(MainWindow);
        actionBootloaderConfigure->setObjectName(QString::fromUtf8("actionBootloaderConfigure"));
        actionBootloaderInfo = new QAction(MainWindow);
        actionBootloaderInfo->setObjectName(QString::fromUtf8("actionBootloaderInfo"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        TerminalWidget = new QWidget(centralwidget);
        TerminalWidget->setObjectName(QString::fromUtf8("TerminalWidget"));
        TerminalWidget->setGeometry(QRect(30, 20, 541, 61));
        TerminalWidget->setAutoFillBackground(false);
        layoutWidget = new QWidget(TerminalWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 23, 531, 31));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        DisconnectButton = new QPushButton(layoutWidget);
        DisconnectButton->setObjectName(QString::fromUtf8("DisconnectButton"));

        gridLayout->addWidget(DisconnectButton, 0, 3, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ConnectButton = new QPushButton(layoutWidget);
        ConnectButton->setObjectName(QString::fromUtf8("ConnectButton"));

        verticalLayout->addWidget(ConnectButton);


        gridLayout->addLayout(verticalLayout, 0, 2, 1, 1);

        RefreshButton = new QPushButton(layoutWidget);
        RefreshButton->setObjectName(QString::fromUtf8("RefreshButton"));

        gridLayout->addWidget(RefreshButton, 0, 4, 1, 1);

        term_comboBox = new QComboBox(layoutWidget);
        term_comboBox->setObjectName(QString::fromUtf8("term_comboBox"));

        gridLayout->addWidget(term_comboBox, 0, 1, 1, 1, Qt::AlignTop);

        term_comboBoxLabel = new QLabel(layoutWidget);
        term_comboBoxLabel->setObjectName(QString::fromUtf8("term_comboBoxLabel"));
        term_comboBoxLabel->setMaximumSize(QSize(91, 23));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        term_comboBoxLabel->setFont(font);

        gridLayout->addWidget(term_comboBoxLabel, 0, 0, 1, 1);

        ConsoleWidget = new QWidget(centralwidget);
        ConsoleWidget->setObjectName(QString::fromUtf8("ConsoleWidget"));
        ConsoleWidget->setGeometry(QRect(20, 130, 551, 441));
        m_console = new Console(ConsoleWidget);
        m_console->setObjectName(QString::fromUtf8("m_console"));
        m_console->setEnabled(true);
        m_console->setGeometry(QRect(10, 0, 531, 371));
        m_console->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        layoutWidget1 = new QWidget(ConsoleWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 390, 311, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        printCheckBox = new QCheckBox(layoutWidget1);
        printCheckBox->setObjectName(QString::fromUtf8("printCheckBox"));
        printCheckBox->setMaximumSize(QSize(61, 19));

        horizontalLayout->addWidget(printCheckBox);

        autoscroll = new QCheckBox(layoutWidget1);
        autoscroll->setObjectName(QString::fromUtf8("autoscroll"));
        autoscroll->setMinimumSize(QSize(91, 20));

        horizontalLayout->addWidget(autoscroll);

        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(51, 23));

        horizontalLayout->addWidget(label);

        rowNbrSpinBox = new QSpinBox(layoutWidget1);
        rowNbrSpinBox->setObjectName(QString::fromUtf8("rowNbrSpinBox"));

        horizontalLayout->addWidget(rowNbrSpinBox);

        parsingLabel = new QLabel(ConsoleWidget);
        parsingLabel->setObjectName(QString::fromUtf8("parsingLabel"));
        parsingLabel->setGeometry(QRect(330, 370, 211, 20));
        QFont font1;
        font1.setItalic(true);
        parsingLabel->setFont(font1);
        clearButton = new QPushButton(ConsoleWidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(470, 400, 74, 21));
        clearButton->setMaximumSize(QSize(74, 21));
        plotWidget = new QWidget(centralwidget);
        plotWidget->setObjectName(QString::fromUtf8("plotWidget"));
        plotWidget->setGeometry(QRect(590, 70, 551, 491));
        plotWidget->setMinimumSize(QSize(500, 401));
        plot = new QCustomPlot(plotWidget);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setGeometry(QRect(10, 0, 521, 431));
        plot->setMinimumSize(QSize(521, 311));
        layoutWidget2 = new QWidget(plotWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(330, 460, 211, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        xAxisRangeLabel = new QLabel(layoutWidget2);
        xAxisRangeLabel->setObjectName(QString::fromUtf8("xAxisRangeLabel"));

        horizontalLayout_3->addWidget(xAxisRangeLabel);

        xAxisAutoRangeCheckbox = new QCheckBox(layoutWidget2);
        xAxisAutoRangeCheckbox->setObjectName(QString::fromUtf8("xAxisAutoRangeCheckbox"));
        xAxisAutoRangeCheckbox->setMaximumSize(QSize(51, 19));

        horizontalLayout_3->addWidget(xAxisAutoRangeCheckbox);

        xAxisRangeSpinbox = new QSpinBox(layoutWidget2);
        xAxisRangeSpinbox->setObjectName(QString::fromUtf8("xAxisRangeSpinbox"));

        horizontalLayout_3->addWidget(xAxisRangeSpinbox);

        layoutWidget3 = new QWidget(plotWidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 460, 131, 23));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        plotCheckBox = new QCheckBox(layoutWidget3);
        plotCheckBox->setObjectName(QString::fromUtf8("plotCheckBox"));

        horizontalLayout_4->addWidget(plotCheckBox);

        clearPlot = new QPushButton(layoutWidget3);
        clearPlot->setObjectName(QString::fromUtf8("clearPlot"));

        horizontalLayout_4->addWidget(clearPlot);

        yAxisLowerLabel = new QLabel(centralwidget);
        yAxisLowerLabel->setObjectName(QString::fromUtf8("yAxisLowerLabel"));
        yAxisLowerLabel->setGeometry(QRect(1000, 20, 26, 16));
        yAxisLowerLabel->setFont(font1);
        yAxisUpperLabel = new QLabel(centralwidget);
        yAxisUpperLabel->setObjectName(QString::fromUtf8("yAxisUpperLabel"));
        yAxisUpperLabel->setGeometry(QRect(1080, 20, 28, 16));
        yAxisUpperLabel->setFont(font1);
        consoleStatusLabel = new QLabel(centralwidget);
        consoleStatusLabel->setObjectName(QString::fromUtf8("consoleStatusLabel"));
        consoleStatusLabel->setGeometry(QRect(30, 20, 531, 16));
        consoleStatusLabel->setFont(font1);
        consoleStatusLabel->setCursor(QCursor(Qt::ArrowCursor));
        consoleStatusLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        txConsoleTextEdit = new QTextEdit(centralwidget);
        txConsoleTextEdit->setObjectName(QString::fromUtf8("txConsoleTextEdit"));
        txConsoleTextEdit->setGeometry(QRect(50, 90, 411, 31));
        txLabel = new QLabel(centralwidget);
        txLabel->setObjectName(QString::fromUtf8("txLabel"));
        txLabel->setGeometry(QRect(30, 90, 21, 16));
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(510, 90, 51, 21));
        crCheckBox = new QCheckBox(centralwidget);
        crCheckBox->setObjectName(QString::fromUtf8("crCheckBox"));
        crCheckBox->setGeometry(QRect(470, 90, 41, 19));
        lfCheckBox = new QCheckBox(centralwidget);
        lfCheckBox->setObjectName(QString::fromUtf8("lfCheckBox"));
        lfCheckBox->setGeometry(QRect(470, 110, 41, 20));
        asciiFormatCheckbox = new QCheckBox(centralwidget);
        asciiFormatCheckbox->setObjectName(QString::fromUtf8("asciiFormatCheckbox"));
        asciiFormatCheckbox->setGeometry(QRect(510, 110, 51, 21));
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(590, 10, 551, 551));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(19, 10, 551, 551));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(840, 40, 294, 25));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        yAxisRangeLabel = new QLabel(widget);
        yAxisRangeLabel->setObjectName(QString::fromUtf8("yAxisRangeLabel"));
        yAxisRangeLabel->setMinimumSize(QSize(81, 16));

        horizontalLayout_2->addWidget(yAxisRangeLabel);

        yAxisAutoRangeCheckbox = new QCheckBox(widget);
        yAxisAutoRangeCheckbox->setObjectName(QString::fromUtf8("yAxisAutoRangeCheckbox"));
        yAxisAutoRangeCheckbox->setMinimumSize(QSize(51, 19));

        horizontalLayout_2->addWidget(yAxisAutoRangeCheckbox);

        yAxisLowerSpinbox = new QSpinBox(widget);
        yAxisLowerSpinbox->setObjectName(QString::fromUtf8("yAxisLowerSpinbox"));
        yAxisLowerSpinbox->setMinimumSize(QSize(71, 23));

        horizontalLayout_2->addWidget(yAxisLowerSpinbox);

        yAxisUpperSpinbox = new QSpinBox(widget);
        yAxisUpperSpinbox->setObjectName(QString::fromUtf8("yAxisUpperSpinbox"));
        yAxisUpperSpinbox->setMinimumSize(QSize(71, 23));

        horizontalLayout_2->addWidget(yAxisUpperSpinbox);

        MainWindow->setCentralWidget(centralwidget);
        frame_3->raise();
        frame->raise();
        TerminalWidget->raise();
        ConsoleWidget->raise();
        plotWidget->raise();
        yAxisRangeLabel->raise();
        yAxisAutoRangeCheckbox->raise();
        yAxisLowerLabel->raise();
        yAxisLowerSpinbox->raise();
        yAxisUpperLabel->raise();
        yAxisUpperSpinbox->raise();
        consoleStatusLabel->raise();
        txConsoleTextEdit->raise();
        txLabel->raise();
        sendButton->raise();
        crCheckBox->raise();
        lfCheckBox->raise();
        asciiFormatCheckbox->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1159, 20));
        menuPort = new QMenu(menubar);
        menuPort->setObjectName(QString::fromUtf8("menuPort"));
        menuConsole = new QMenu(menubar);
        menuConsole->setObjectName(QString::fromUtf8("menuConsole"));
        menuLogs = new QMenu(menubar);
        menuLogs->setObjectName(QString::fromUtf8("menuLogs"));
        menuSTM32_Bootloader = new QMenu(menubar);
        menuSTM32_Bootloader->setObjectName(QString::fromUtf8("menuSTM32_Bootloader"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuPort->menuAction());
        menubar->addAction(menuConsole->menuAction());
        menubar->addAction(menuLogs->menuAction());
        menubar->addAction(menuSTM32_Bootloader->menuAction());
        menuPort->addAction(actionConnect);
        menuPort->addAction(actionRefresh);
        menuPort->addAction(actionDisconnect);
        menuPort->addSeparator();
        menuPort->addAction(actionConfigurePort);
        menuConsole->addAction(actionClear);
        menuConsole->addAction(actionToggle_Auto_Scroll);
        menuConsole->addAction(actionParsing);
        menuLogs->addAction(actionStart_logging);
        menuLogs->addAction(actionStop_logging);
        menuLogs->addAction(actionConfigure_logging);
        menuSTM32_Bootloader->addAction(actionBootloaderConfigure);
        menuSTM32_Bootloader->addAction(actionBootloaderInfo);

        retranslateUi(MainWindow);

        term_comboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Terminal", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        actionRefresh->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        actionDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        actionClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        actionToggle_Auto_Scroll->setText(QCoreApplication::translate("MainWindow", "Toggle Auto-Scroll", nullptr));
        actionConfigure->setText(QCoreApplication::translate("MainWindow", "Configure", nullptr));
        actionConfigurePort->setText(QCoreApplication::translate("MainWindow", "Configure", nullptr));
        actionParsing->setText(QCoreApplication::translate("MainWindow", "Parsing settings", nullptr));
        actionStart_logging->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        actionStop_logging->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        actionConfigure_logging->setText(QCoreApplication::translate("MainWindow", "Configure", nullptr));
        actionBootloaderConfigure->setText(QCoreApplication::translate("MainWindow", "Configure", nullptr));
        actionBootloaderInfo->setText(QCoreApplication::translate("MainWindow", "Info", nullptr));
        DisconnectButton->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        ConnectButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        RefreshButton->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        term_comboBoxLabel->setText(QCoreApplication::translate("MainWindow", "Available ports:", nullptr));
        printCheckBox->setText(QCoreApplication::translate("MainWindow", "Print", nullptr));
        autoscroll->setText(QCoreApplication::translate("MainWindow", "auto-scroll", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "max rows:", nullptr));
        parsingLabel->setText(QCoreApplication::translate("MainWindow", "parsing: [13][LSB][DATA][DATA][MSB][CS]", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        xAxisRangeLabel->setText(QCoreApplication::translate("MainWindow", "x-axis range:", nullptr));
        xAxisAutoRangeCheckbox->setText(QCoreApplication::translate("MainWindow", "auto", nullptr));
        plotCheckBox->setText(QCoreApplication::translate("MainWindow", "Plot", nullptr));
        clearPlot->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        yAxisLowerLabel->setText(QCoreApplication::translate("MainWindow", "lower", nullptr));
        yAxisUpperLabel->setText(QCoreApplication::translate("MainWindow", "upper", nullptr));
        consoleStatusLabel->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        txLabel->setText(QCoreApplication::translate("MainWindow", "TX:", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        crCheckBox->setText(QCoreApplication::translate("MainWindow", "CR", nullptr));
        lfCheckBox->setText(QCoreApplication::translate("MainWindow", "LF", nullptr));
        asciiFormatCheckbox->setText(QCoreApplication::translate("MainWindow", "ASCII", nullptr));
        yAxisRangeLabel->setText(QCoreApplication::translate("MainWindow", "y-axis range:", nullptr));
        yAxisAutoRangeCheckbox->setText(QCoreApplication::translate("MainWindow", "auto", nullptr));
        menuPort->setTitle(QCoreApplication::translate("MainWindow", "Port", nullptr));
        menuConsole->setTitle(QCoreApplication::translate("MainWindow", "Console", nullptr));
        menuLogs->setTitle(QCoreApplication::translate("MainWindow", "Logs", nullptr));
        menuSTM32_Bootloader->setTitle(QCoreApplication::translate("MainWindow", "STM32 Bootloader", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
