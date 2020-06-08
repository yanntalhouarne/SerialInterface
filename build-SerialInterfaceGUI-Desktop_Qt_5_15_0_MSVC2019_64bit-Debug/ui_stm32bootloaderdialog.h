/********************************************************************************
** Form generated from reading UI file 'stm32bootloaderdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STM32BOOTLOADERDIALOG_H
#define UI_STM32BOOTLOADERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stm32bootloaderDialog
{
public:
    QPushButton *hexFilePathApplyBtn;
    QLabel *adressLabel;
    QLineEdit *adressLineEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *hexFilePathLabel;
    QLineEdit *hexFilePathLineEdit;
    QPushButton *hexFilePathSelectBtn;

    void setupUi(QDialog *stm32bootloaderDialog)
    {
        if (stm32bootloaderDialog->objectName().isEmpty())
            stm32bootloaderDialog->setObjectName(QString::fromUtf8("stm32bootloaderDialog"));
        stm32bootloaderDialog->resize(391, 139);
        hexFilePathApplyBtn = new QPushButton(stm32bootloaderDialog);
        hexFilePathApplyBtn->setObjectName(QString::fromUtf8("hexFilePathApplyBtn"));
        hexFilePathApplyBtn->setGeometry(QRect(170, 90, 61, 21));
        adressLabel = new QLabel(stm32bootloaderDialog);
        adressLabel->setObjectName(QString::fromUtf8("adressLabel"));
        adressLabel->setGeometry(QRect(40, 60, 47, 13));
        adressLineEdit = new QLineEdit(stm32bootloaderDialog);
        adressLineEdit->setObjectName(QString::fromUtf8("adressLineEdit"));
        adressLineEdit->setGeometry(QRect(80, 60, 71, 21));
        widget = new QWidget(stm32bootloaderDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 20, 311, 24));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        hexFilePathLabel = new QLabel(widget);
        hexFilePathLabel->setObjectName(QString::fromUtf8("hexFilePathLabel"));

        horizontalLayout->addWidget(hexFilePathLabel);

        hexFilePathLineEdit = new QLineEdit(widget);
        hexFilePathLineEdit->setObjectName(QString::fromUtf8("hexFilePathLineEdit"));

        horizontalLayout->addWidget(hexFilePathLineEdit);

        hexFilePathSelectBtn = new QPushButton(widget);
        hexFilePathSelectBtn->setObjectName(QString::fromUtf8("hexFilePathSelectBtn"));
        hexFilePathSelectBtn->setMaximumSize(QSize(31, 21));

        horizontalLayout->addWidget(hexFilePathSelectBtn);


        retranslateUi(stm32bootloaderDialog);

        QMetaObject::connectSlotsByName(stm32bootloaderDialog);
    } // setupUi

    void retranslateUi(QDialog *stm32bootloaderDialog)
    {
        stm32bootloaderDialog->setWindowTitle(QCoreApplication::translate("stm32bootloaderDialog", "Dialog", nullptr));
        hexFilePathApplyBtn->setText(QCoreApplication::translate("stm32bootloaderDialog", "Apply", nullptr));
        adressLabel->setText(QCoreApplication::translate("stm32bootloaderDialog", "Adress:", nullptr));
        hexFilePathLabel->setText(QCoreApplication::translate("stm32bootloaderDialog", ".hex file:", nullptr));
        hexFilePathSelectBtn->setText(QCoreApplication::translate("stm32bootloaderDialog", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stm32bootloaderDialog: public Ui_stm32bootloaderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STM32BOOTLOADERDIALOG_H
