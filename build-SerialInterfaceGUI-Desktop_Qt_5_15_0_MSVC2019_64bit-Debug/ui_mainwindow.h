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
    QVBoxLayout *verticalLayout_2;
    QLabel *consoleStatusLabel;
    Console *m_console;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *printCheckBox;
    QCheckBox *autoscroll;
    QPushButton *clearButton;
    QWidget *plotWidget;
    QCustomPlot *plot;
    QPushButton *clearPlot;
    QCheckBox *plotCheckBox;
    QLabel *axisRangeLabel;
    QSpinBox *axisRangeSpinBox;
    QMenuBar *menubar;
    QMenu *menuPort;
    QMenu *menuConsole;
    QMenu *menuConfigure;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1186, 496);
        MainWindow->setMinimumSize(QSize(620, 496));
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
        verticalLayout_2 = new QVBoxLayout(ConsoleWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        consoleStatusLabel = new QLabel(ConsoleWidget);
        consoleStatusLabel->setObjectName(QString::fromUtf8("consoleStatusLabel"));
        consoleStatusLabel->setCursor(QCursor(Qt::ArrowCursor));
        consoleStatusLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_2->addWidget(consoleStatusLabel);

        m_console = new Console(ConsoleWidget);
        m_console->setObjectName(QString::fromUtf8("m_console"));
        m_console->setEnabled(true);
        m_console->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        verticalLayout_2->addWidget(m_console);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        printCheckBox = new QCheckBox(ConsoleWidget);
        printCheckBox->setObjectName(QString::fromUtf8("printCheckBox"));

        horizontalLayout_2->addWidget(printCheckBox);

        autoscroll = new QCheckBox(ConsoleWidget);
        autoscroll->setObjectName(QString::fromUtf8("autoscroll"));

        horizontalLayout_2->addWidget(autoscroll);

        clearButton = new QPushButton(ConsoleWidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setMaximumSize(QSize(74, 21));

        horizontalLayout_2->addWidget(clearButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        plotWidget = new QWidget(centralwidget);
        plotWidget->setObjectName(QString::fromUtf8("plotWidget"));
        plotWidget->setGeometry(QRect(590, 80, 501, 371));
        plot = new QCustomPlot(plotWidget);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setGeometry(QRect(10, 0, 521, 341));
        plot->setMinimumSize(QSize(521, 311));
        clearPlot = new QPushButton(plotWidget);
        clearPlot->setObjectName(QString::fromUtf8("clearPlot"));
        clearPlot->setGeometry(QRect(420, 350, 80, 21));
        plotCheckBox = new QCheckBox(plotWidget);
        plotCheckBox->setObjectName(QString::fromUtf8("plotCheckBox"));
        plotCheckBox->setGeometry(QRect(10, 350, 72, 19));
        axisRangeLabel = new QLabel(plotWidget);
        axisRangeLabel->setObjectName(QString::fromUtf8("axisRangeLabel"));
        axisRangeLabel->setGeometry(QRect(140, 350, 61, 20));
        axisRangeSpinBox = new QSpinBox(plotWidget);
        axisRangeSpinBox->setObjectName(QString::fromUtf8("axisRangeSpinBox"));
        axisRangeSpinBox->setGeometry(QRect(210, 350, 51, 22));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1186, 20));
        menuPort = new QMenu(menubar);
        menuPort->setObjectName(QString::fromUtf8("menuPort"));
        menuConsole = new QMenu(menubar);
        menuConsole->setObjectName(QString::fromUtf8("menuConsole"));
        menuConfigure = new QMenu(menubar);
        menuConfigure->setObjectName(QString::fromUtf8("menuConfigure"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuPort->menuAction());
        menubar->addAction(menuConsole->menuAction());
        menubar->addAction(menuConfigure->menuAction());
        menuPort->addAction(actionConnect);
        menuPort->addAction(actionRefresh);
        menuPort->addAction(actionDisconnect);
        menuPort->addSeparator();
        menuConsole->addAction(actionClear);
        menuConsole->addAction(actionToggle_Auto_Scroll);
        menuConsole->addAction(actionParsing);
        menuConfigure->addAction(actionConfigurePort);

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
        ConnectButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        RefreshButton->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        DisconnectButton->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        term_comboBoxLabel->setText(QCoreApplication::translate("MainWindow", "Available ports:", nullptr));
        consoleStatusLabel->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        printCheckBox->setText(QCoreApplication::translate("MainWindow", "Print", nullptr));
        autoscroll->setText(QCoreApplication::translate("MainWindow", "auto-scroll", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        clearPlot->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        plotCheckBox->setText(QCoreApplication::translate("MainWindow", "Plot", nullptr));
        axisRangeLabel->setText(QCoreApplication::translate("MainWindow", "x-axis range:", nullptr));
        menuPort->setTitle(QCoreApplication::translate("MainWindow", "Port", nullptr));
        menuConsole->setTitle(QCoreApplication::translate("MainWindow", "Console", nullptr));
        menuConfigure->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
