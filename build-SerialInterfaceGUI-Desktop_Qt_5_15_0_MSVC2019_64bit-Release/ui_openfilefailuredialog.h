/********************************************************************************
** Form generated from reading UI file 'openfilefailuredialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENFILEFAILUREDIALOG_H
#define UI_OPENFILEFAILUREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_OpenFileFailureDialog
{
public:
    QPushButton *openFileFailureButton;
    QLabel *openFileFailureLabel;

    void setupUi(QDialog *OpenFileFailureDialog)
    {
        if (OpenFileFailureDialog->objectName().isEmpty())
            OpenFileFailureDialog->setObjectName(QString::fromUtf8("OpenFileFailureDialog"));
        OpenFileFailureDialog->resize(164, 87);
        openFileFailureButton = new QPushButton(OpenFileFailureDialog);
        openFileFailureButton->setObjectName(QString::fromUtf8("openFileFailureButton"));
        openFileFailureButton->setGeometry(QRect(60, 50, 41, 21));
        openFileFailureLabel = new QLabel(OpenFileFailureDialog);
        openFileFailureLabel->setObjectName(QString::fromUtf8("openFileFailureLabel"));
        openFileFailureLabel->setGeometry(QRect(40, 20, 101, 16));

        retranslateUi(OpenFileFailureDialog);

        QMetaObject::connectSlotsByName(OpenFileFailureDialog);
    } // setupUi

    void retranslateUi(QDialog *OpenFileFailureDialog)
    {
        OpenFileFailureDialog->setWindowTitle(QCoreApplication::translate("OpenFileFailureDialog", "Dialog", nullptr));
        openFileFailureButton->setText(QCoreApplication::translate("OpenFileFailureDialog", "close", nullptr));
        openFileFailureLabel->setText(QCoreApplication::translate("OpenFileFailureDialog", "Could not open file.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpenFileFailureDialog: public Ui_OpenFileFailureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENFILEFAILUREDIALOG_H