/********************************************************************************
** Form generated from reading UI file 'portconnfailuredialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORTCONNFAILUREDIALOG_H
#define UI_PORTCONNFAILUREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PortConnFailureDialog
{
public:
    QPushButton *portConnFailureButton;
    QLabel *portConnFailureLabel;

    void setupUi(QDialog *PortConnFailureDialog)
    {
        if (PortConnFailureDialog->objectName().isEmpty())
            PortConnFailureDialog->setObjectName(QString::fromUtf8("PortConnFailureDialog"));
        PortConnFailureDialog->resize(196, 82);
        portConnFailureButton = new QPushButton(PortConnFailureDialog);
        portConnFailureButton->setObjectName(QString::fromUtf8("portConnFailureButton"));
        portConnFailureButton->setGeometry(QRect(80, 50, 41, 20));
        portConnFailureLabel = new QLabel(PortConnFailureDialog);
        portConnFailureLabel->setObjectName(QString::fromUtf8("portConnFailureLabel"));
        portConnFailureLabel->setGeometry(QRect(20, 20, 161, 16));

        retranslateUi(PortConnFailureDialog);

        QMetaObject::connectSlotsByName(PortConnFailureDialog);
    } // setupUi

    void retranslateUi(QDialog *PortConnFailureDialog)
    {
        PortConnFailureDialog->setWindowTitle(QCoreApplication::translate("PortConnFailureDialog", "Dialog", nullptr));
        portConnFailureButton->setText(QCoreApplication::translate("PortConnFailureDialog", "close", nullptr));
        portConnFailureLabel->setText(QCoreApplication::translate("PortConnFailureDialog", "Can't open %1, error code %2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PortConnFailureDialog: public Ui_PortConnFailureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTCONNFAILUREDIALOG_H
