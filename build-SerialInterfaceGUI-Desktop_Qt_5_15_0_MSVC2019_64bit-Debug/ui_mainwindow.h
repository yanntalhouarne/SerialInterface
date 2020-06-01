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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
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
    QWidget *centralwidget;
    QWidget *TerminalWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *ConnectButton;
    QPushButton *RefreshButton;
    QComboBox *term_comboBox;
    QPushButton *DisconnectButton;
    QLabel *term_comboBoxLabel;
    QWidget *ConsoleWidget;
    QLabel *consoleStatusLabel;
    Console *m_console;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QCheckBox *printCheckBox;
    QPushButton *clearButton;
    QCheckBox *autoscroll;
    QWidget *plotWidget;
    QCustomPlot *plot;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *xAxisRangeLabel;
    QCheckBox *xAxisAutoRangeCheckbox;
    QLabel *xAxisRange;
    QSpinBox *xAxisRangeSpinbox;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *plotCheckBox;
    QPushButton *clearPlot;
    QLabel *yAxisRangeLabel;
    QCheckBox *yAxisAutoRangeCheckbox;
    QLabel *yAxisLowerLabel;
    QSpinBox *yAxisLowerSpinbox;
    QLabel *yAxisUpperLabel;
    QSpinBox *yAxisUpperSpinbox;
    QMenuBar *menubar;
    QMenu *menuPort;
    QMenu *menuConsole;
    QMenu *menuConfigure;
    QMenu *menuLogs;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1131, 504);
        MainWindow->setMinimumSize(QSize(1115, 499));
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
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        TerminalWidget = new QWidget(centralwidget);
        TerminalWidget->setObjectName(QString::fromUtf8("TerminalWidget"));
        TerminalWidget->setGeometry(QRect(20, 0, 541, 61));
        TerminalWidget->setAutoFillBackground(false);
        layoutWidget = new QWidget(TerminalWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 531, 44));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ConnectButton = new QPushButton(layoutWidget);
        ConnectButton->setObjectName(QString::fromUtf8("ConnectButton"));

        verticalLayout->addWidget(ConnectButton);


        gridLayout->addLayout(verticalLayout, 0, 3, 1, 1);

        RefreshButton = new QPushButton(layoutWidget);
        RefreshButton->setObjectName(QString::fromUtf8("RefreshButton"));

        gridLayout->addWidget(RefreshButton, 0, 5, 1, 1);

        term_comboBox = new QComboBox(layoutWidget);
        term_comboBox->setObjectName(QString::fromUtf8("term_comboBox"));

        gridLayout->addWidget(term_comboBox, 0, 2, 1, 1, Qt::AlignTop);

        DisconnectButton = new QPushButton(layoutWidget);
        DisconnectButton->setObjectName(QString::fromUtf8("DisconnectButton"));

        gridLayout->addWidget(DisconnectButton, 0, 4, 1, 1);

        term_comboBoxLabel = new QLabel(layoutWidget);
        term_comboBoxLabel->setObjectName(QString::fromUtf8("term_comboBoxLabel"));

        gridLayout->addWidget(term_comboBoxLabel, 0, 0, 1, 1);

        ConsoleWidget = new QWidget(centralwidget);
        ConsoleWidget->setObjectName(QString::fromUtf8("ConsoleWidget"));
        ConsoleWidget->setGeometry(QRect(20, 50, 551, 411));
        consoleStatusLabel = new QLabel(ConsoleWidget);
        consoleStatusLabel->setObjectName(QString::fromUtf8("consoleStatusLabel"));
        consoleStatusLabel->setGeometry(QRect(9, 9, 531, 16));
        consoleStatusLabel->setCursor(QCursor(Qt::ArrowCursor));
        consoleStatusLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        m_console = new Console(ConsoleWidget);
        m_console->setObjectName(QString::fromUtf8("m_console"));
        m_console->setEnabled(true);
        m_console->setGeometry(QRect(9, 28, 531, 351));
        m_console->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        layoutWidget1 = new QWidget(ConsoleWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 380, 210, 23));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        printCheckBox = new QCheckBox(layoutWidget1);
        printCheckBox->setObjectName(QString::fromUtf8("printCheckBox"));

        horizontalLayout->addWidget(printCheckBox);

        clearButton = new QPushButton(layoutWidget1);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setMaximumSize(QSize(74, 21));

        horizontalLayout->addWidget(clearButton);

        autoscroll = new QCheckBox(layoutWidget1);
        autoscroll->setObjectName(QString::fromUtf8("autoscroll"));

        horizontalLayout->addWidget(autoscroll);

        plotWidget = new QWidget(centralwidget);
        plotWidget->setObjectName(QString::fromUtf8("plotWidget"));
        plotWidget->setGeometry(QRect(570, 60, 731, 401));
        plotWidget->setMinimumSize(QSize(731, 401));
        plot = new QCustomPlot(plotWidget);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setGeometry(QRect(10, 0, 521, 361));
        plot->setMinimumSize(QSize(521, 311));
        layoutWidget2 = new QWidget(plotWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(315, 370, 211, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        xAxisRangeLabel = new QLabel(layoutWidget2);
        xAxisRangeLabel->setObjectName(QString::fromUtf8("xAxisRangeLabel"));

        horizontalLayout_3->addWidget(xAxisRangeLabel);

        xAxisAutoRangeCheckbox = new QCheckBox(layoutWidget2);
        xAxisAutoRangeCheckbox->setObjectName(QString::fromUtf8("xAxisAutoRangeCheckbox"));

        horizontalLayout_3->addWidget(xAxisAutoRangeCheckbox);

        xAxisRange = new QLabel(layoutWidget2);
        xAxisRange->setObjectName(QString::fromUtf8("xAxisRange"));

        horizontalLayout_3->addWidget(xAxisRange);

        xAxisRangeSpinbox = new QSpinBox(layoutWidget2);
        xAxisRangeSpinbox->setObjectName(QString::fromUtf8("xAxisRangeSpinbox"));

        horizontalLayout_3->addWidget(xAxisRangeSpinbox);

        layoutWidget3 = new QWidget(plotWidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 370, 131, 23));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        plotCheckBox = new QCheckBox(layoutWidget3);
        plotCheckBox->setObjectName(QString::fromUtf8("plotCheckBox"));

        horizontalLayout_4->addWidget(plotCheckBox);

        clearPlot = new QPushButton(layoutWidget3);
        clearPlot->setObjectName(QString::fromUtf8("clearPlot"));

        horizontalLayout_4->addWidget(clearPlot);

        yAxisRangeLabel = new QLabel(centralwidget);
        yAxisRangeLabel->setObjectName(QString::fromUtf8("yAxisRangeLabel"));
        yAxisRangeLabel->setGeometry(QRect(830, 30, 64, 16));
        yAxisAutoRangeCheckbox = new QCheckBox(centralwidget);
        yAxisAutoRangeCheckbox->setObjectName(QString::fromUtf8("yAxisAutoRangeCheckbox"));
        yAxisAutoRangeCheckbox->setGeometry(QRect(900, 30, 47, 19));
        yAxisLowerLabel = new QLabel(centralwidget);
        yAxisLowerLabel->setObjectName(QString::fromUtf8("yAxisLowerLabel"));
        yAxisLowerLabel->setGeometry(QRect(970, 10, 26, 16));
        yAxisLowerSpinbox = new QSpinBox(centralwidget);
        yAxisLowerSpinbox->setObjectName(QString::fromUtf8("yAxisLowerSpinbox"));
        yAxisLowerSpinbox->setGeometry(QRect(950, 30, 71, 23));
        yAxisUpperLabel = new QLabel(centralwidget);
        yAxisUpperLabel->setObjectName(QString::fromUtf8("yAxisUpperLabel"));
        yAxisUpperLabel->setGeometry(QRect(1050, 10, 28, 16));
        yAxisUpperSpinbox = new QSpinBox(centralwidget);
        yAxisUpperSpinbox->setObjectName(QString::fromUtf8("yAxisUpperSpinbox"));
        yAxisUpperSpinbox->setGeometry(QRect(1030, 30, 71, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1131, 20));
        menuPort = new QMenu(menubar);
        menuPort->setObjectName(QString::fromUtf8("menuPort"));
        menuConsole = new QMenu(menubar);
        menuConsole->setObjectName(QString::fromUtf8("menuConsole"));
        menuConfigure = new QMenu(menubar);
        menuConfigure->setObjectName(QString::fromUtf8("menuConfigure"));
        menuLogs = new QMenu(menubar);
        menuLogs->setObjectName(QString::fromUtf8("menuLogs"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuPort->menuAction());
        menubar->addAction(menuConsole->menuAction());
        menubar->addAction(menuConfigure->menuAction());
        menubar->addAction(menuLogs->menuAction());
        menuPort->addAction(actionConnect);
        menuPort->addAction(actionRefresh);
        menuPort->addAction(actionDisconnect);
        menuPort->addSeparator();
        menuConsole->addAction(actionClear);
        menuConsole->addAction(actionToggle_Auto_Scroll);
        menuConsole->addAction(actionParsing);
        menuConfigure->addAction(actionConfigurePort);
        menuLogs->addAction(actionStart_logging);
        menuLogs->addAction(actionStop_logging);
        menuLogs->addAction(actionConfigure_logging);

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
        ConnectButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        RefreshButton->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        DisconnectButton->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        term_comboBoxLabel->setText(QCoreApplication::translate("MainWindow", "Available ports:", nullptr));
        consoleStatusLabel->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        printCheckBox->setText(QCoreApplication::translate("MainWindow", "Print", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        autoscroll->setText(QCoreApplication::translate("MainWindow", "auto-scroll", nullptr));
        xAxisRangeLabel->setText(QCoreApplication::translate("MainWindow", "x-axis range:", nullptr));
        xAxisAutoRangeCheckbox->setText(QCoreApplication::translate("MainWindow", "auto", nullptr));
        xAxisRange->setText(QCoreApplication::translate("MainWindow", "range", nullptr));
        plotCheckBox->setText(QCoreApplication::translate("MainWindow", "Plot", nullptr));
        clearPlot->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        yAxisRangeLabel->setText(QCoreApplication::translate("MainWindow", "y-axis range:", nullptr));
        yAxisAutoRangeCheckbox->setText(QCoreApplication::translate("MainWindow", "auto", nullptr));
        yAxisLowerLabel->setText(QCoreApplication::translate("MainWindow", "lower", nullptr));
        yAxisUpperLabel->setText(QCoreApplication::translate("MainWindow", "upper", nullptr));
        menuPort->setTitle(QCoreApplication::translate("MainWindow", "Port", nullptr));
        menuConsole->setTitle(QCoreApplication::translate("MainWindow", "Console", nullptr));
        menuConfigure->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        menuLogs->setTitle(QCoreApplication::translate("MainWindow", "Logs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
