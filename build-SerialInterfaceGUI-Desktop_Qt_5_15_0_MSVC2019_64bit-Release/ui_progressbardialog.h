/********************************************************************************
** Form generated from reading UI file 'progressbardialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSBARDIALOG_H
#define UI_PROGRESSBARDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_progressBarDialog
{
public:
    QProgressBar *progressBar;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *progressBarDialog)
    {
        if (progressBarDialog->objectName().isEmpty())
            progressBarDialog->setObjectName(QString::fromUtf8("progressBarDialog"));
        progressBarDialog->resize(276, 145);
        progressBar = new QProgressBar(progressBarDialog);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(50, 70, 171, 23));
        progressBar->setValue(24);
        label = new QLabel(progressBarDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 161, 21));
        pushButton = new QPushButton(progressBarDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 110, 41, 21));
        pushButton_2 = new QPushButton(progressBarDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(219, 110, 41, 21));

        retranslateUi(progressBarDialog);

        QMetaObject::connectSlotsByName(progressBarDialog);
    } // setupUi

    void retranslateUi(QDialog *progressBarDialog)
    {
        progressBarDialog->setWindowTitle(QCoreApplication::translate("progressBarDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("progressBarDialog", "Writing to flash...", nullptr));
        pushButton->setText(QCoreApplication::translate("progressBarDialog", "done", nullptr));
        pushButton_2->setText(QCoreApplication::translate("progressBarDialog", "Abort", nullptr));
    } // retranslateUi

};

namespace Ui {
    class progressBarDialog: public Ui_progressBarDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSBARDIALOG_H
