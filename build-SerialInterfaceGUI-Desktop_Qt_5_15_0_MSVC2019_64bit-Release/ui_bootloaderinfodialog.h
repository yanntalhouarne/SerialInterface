/********************************************************************************
** Form generated from reading UI file 'bootloaderinfodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOTLOADERINFODIALOG_H
#define UI_BOOTLOADERINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_bootloaderInfoDialog
{
public:
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *bootloaderInfoDialog)
    {
        if (bootloaderInfoDialog->objectName().isEmpty())
            bootloaderInfoDialog->setObjectName(QString::fromUtf8("bootloaderInfoDialog"));
        bootloaderInfoDialog->resize(447, 181);
        plainTextEdit = new QPlainTextEdit(bootloaderInfoDialog);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(0, 0, 451, 181));

        retranslateUi(bootloaderInfoDialog);

        QMetaObject::connectSlotsByName(bootloaderInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *bootloaderInfoDialog)
    {
        bootloaderInfoDialog->setWindowTitle(QCoreApplication::translate("bootloaderInfoDialog", "Dialog", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("bootloaderInfoDialog", "		SUPPORTED COMMANDS:\n"
"\n"
"- INIT (0x7F): initialize the STM32 device. The device must be in bootloader mode.\n"
"\n"
"- GET_ID (0x02): get the ID of the STM32 device.\n"
"\n"
"- ERASE_SECTORS_0_TO_4 (0x98): erases sectors 0, 1, 2, 3 and 4.\n"
"\n"
"- UPLOAD_BIN_FILE (0x99): writes the content of the selected BIN file to flash memory.\n"
"\n"
"\n"
"Tested on STM32F72xx.\n"
"", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bootloaderInfoDialog: public Ui_bootloaderInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOTLOADERINFODIALOG_H
