/********************************************************************************
** Form generated from reading UI file 'portSettingsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORTSETTINGSDIALOG_H
#define UI_PORTSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_portSettingsDialog
{
public:
    QGroupBox *selectSerialPortBox;
    QVBoxLayout *verticalLayout;
    QComboBox *serialPortInfoListBox;
    QLabel *descriptionLabel;
    QLabel *manufacturerLabel;
    QLabel *serialNumberLabel;
    QLabel *locationLabel;
    QLabel *vidLabel;
    QLabel *pidLabel;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *baudRateLabel;
    QLabel *dataBitsLabel;
    QLabel *parityLabel;
    QLabel *stopBitsLabel;
    QLabel *flowControlLabel;
    QComboBox *flowControlBox;
    QComboBox *stopBitsBox;
    QComboBox *baudRateBox;
    QComboBox *dataBitsBox;
    QComboBox *parityBox;
    QPushButton *ApplyButton;

    void setupUi(QDialog *portSettingsDialog)
    {
        if (portSettingsDialog->objectName().isEmpty())
            portSettingsDialog->setObjectName(QString::fromUtf8("portSettingsDialog"));
        portSettingsDialog->resize(405, 250);
        selectSerialPortBox = new QGroupBox(portSettingsDialog);
        selectSerialPortBox->setObjectName(QString::fromUtf8("selectSerialPortBox"));
        selectSerialPortBox->setGeometry(QRect(10, 10, 181, 191));
        verticalLayout = new QVBoxLayout(selectSerialPortBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        serialPortInfoListBox = new QComboBox(selectSerialPortBox);
        serialPortInfoListBox->setObjectName(QString::fromUtf8("serialPortInfoListBox"));

        verticalLayout->addWidget(serialPortInfoListBox);

        descriptionLabel = new QLabel(selectSerialPortBox);
        descriptionLabel->setObjectName(QString::fromUtf8("descriptionLabel"));

        verticalLayout->addWidget(descriptionLabel);

        manufacturerLabel = new QLabel(selectSerialPortBox);
        manufacturerLabel->setObjectName(QString::fromUtf8("manufacturerLabel"));

        verticalLayout->addWidget(manufacturerLabel);

        serialNumberLabel = new QLabel(selectSerialPortBox);
        serialNumberLabel->setObjectName(QString::fromUtf8("serialNumberLabel"));

        verticalLayout->addWidget(serialNumberLabel);

        locationLabel = new QLabel(selectSerialPortBox);
        locationLabel->setObjectName(QString::fromUtf8("locationLabel"));

        verticalLayout->addWidget(locationLabel);

        vidLabel = new QLabel(selectSerialPortBox);
        vidLabel->setObjectName(QString::fromUtf8("vidLabel"));

        verticalLayout->addWidget(vidLabel);

        pidLabel = new QLabel(selectSerialPortBox);
        pidLabel->setObjectName(QString::fromUtf8("pidLabel"));

        verticalLayout->addWidget(pidLabel);

        groupBox = new QGroupBox(portSettingsDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(200, 10, 191, 191));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 19, 171, 171));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        baudRateLabel = new QLabel(gridLayoutWidget);
        baudRateLabel->setObjectName(QString::fromUtf8("baudRateLabel"));
        baudRateLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(baudRateLabel, 0, 0, 1, 1);

        dataBitsLabel = new QLabel(gridLayoutWidget);
        dataBitsLabel->setObjectName(QString::fromUtf8("dataBitsLabel"));
        dataBitsLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(dataBitsLabel, 1, 0, 1, 1);

        parityLabel = new QLabel(gridLayoutWidget);
        parityLabel->setObjectName(QString::fromUtf8("parityLabel"));
        parityLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(parityLabel, 2, 0, 1, 1);

        stopBitsLabel = new QLabel(gridLayoutWidget);
        stopBitsLabel->setObjectName(QString::fromUtf8("stopBitsLabel"));
        stopBitsLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(stopBitsLabel, 3, 0, 1, 1);

        flowControlLabel = new QLabel(gridLayoutWidget);
        flowControlLabel->setObjectName(QString::fromUtf8("flowControlLabel"));
        flowControlLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(flowControlLabel, 4, 0, 1, 1);

        flowControlBox = new QComboBox(gridLayoutWidget);
        flowControlBox->setObjectName(QString::fromUtf8("flowControlBox"));

        gridLayout->addWidget(flowControlBox, 4, 1, 1, 1);

        stopBitsBox = new QComboBox(gridLayoutWidget);
        stopBitsBox->setObjectName(QString::fromUtf8("stopBitsBox"));

        gridLayout->addWidget(stopBitsBox, 3, 1, 1, 1);

        baudRateBox = new QComboBox(gridLayoutWidget);
        baudRateBox->setObjectName(QString::fromUtf8("baudRateBox"));

        gridLayout->addWidget(baudRateBox, 0, 1, 1, 1);

        dataBitsBox = new QComboBox(gridLayoutWidget);
        dataBitsBox->setObjectName(QString::fromUtf8("dataBitsBox"));

        gridLayout->addWidget(dataBitsBox, 1, 1, 1, 1);

        parityBox = new QComboBox(gridLayoutWidget);
        parityBox->setObjectName(QString::fromUtf8("parityBox"));

        gridLayout->addWidget(parityBox, 2, 1, 1, 1);

        ApplyButton = new QPushButton(portSettingsDialog);
        ApplyButton->setObjectName(QString::fromUtf8("ApplyButton"));
        ApplyButton->setGeometry(QRect(300, 220, 80, 21));

        retranslateUi(portSettingsDialog);

        QMetaObject::connectSlotsByName(portSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *portSettingsDialog)
    {
        portSettingsDialog->setWindowTitle(QCoreApplication::translate("portSettingsDialog", "Serial port settings", nullptr));
        selectSerialPortBox->setTitle(QCoreApplication::translate("portSettingsDialog", "Serial port", nullptr));
        descriptionLabel->setText(QCoreApplication::translate("portSettingsDialog", "Description:", nullptr));
        manufacturerLabel->setText(QCoreApplication::translate("portSettingsDialog", "Manufacturer:", nullptr));
        serialNumberLabel->setText(QCoreApplication::translate("portSettingsDialog", "Serial Number:", nullptr));
        locationLabel->setText(QCoreApplication::translate("portSettingsDialog", "Location:", nullptr));
        vidLabel->setText(QCoreApplication::translate("portSettingsDialog", "Vendor ID:", nullptr));
        pidLabel->setText(QCoreApplication::translate("portSettingsDialog", "Product ID:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("portSettingsDialog", "Parameters", nullptr));
        baudRateLabel->setText(QCoreApplication::translate("portSettingsDialog", "BaudRate:", nullptr));
        dataBitsLabel->setText(QCoreApplication::translate("portSettingsDialog", "Data Bits:", nullptr));
        parityLabel->setText(QCoreApplication::translate("portSettingsDialog", "Parity:", nullptr));
        stopBitsLabel->setText(QCoreApplication::translate("portSettingsDialog", "Stop bits:", nullptr));
        flowControlLabel->setText(QCoreApplication::translate("portSettingsDialog", "Flow control:", nullptr));
        ApplyButton->setText(QCoreApplication::translate("portSettingsDialog", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class portSettingsDialog: public Ui_portSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTSETTINGSDIALOG_H
