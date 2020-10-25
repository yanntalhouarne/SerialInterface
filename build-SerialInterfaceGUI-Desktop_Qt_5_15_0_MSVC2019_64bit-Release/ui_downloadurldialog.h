/********************************************************************************
** Form generated from reading UI file 'downloadurldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADURLDIALOG_H
#define UI_DOWNLOADURLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_downloadUrlDialog
{
public:
    QLabel *urlLabel;
    QLineEdit *urlLineEdit;
    QPushButton *downloadUrlBtn;

    void setupUi(QDialog *downloadUrlDialog)
    {
        if (downloadUrlDialog->objectName().isEmpty())
            downloadUrlDialog->setObjectName(QString::fromUtf8("downloadUrlDialog"));
        downloadUrlDialog->resize(446, 129);
        downloadUrlDialog->setModal(false);
        urlLabel = new QLabel(downloadUrlDialog);
        urlLabel->setObjectName(QString::fromUtf8("urlLabel"));
        urlLabel->setGeometry(QRect(30, 40, 21, 16));
        urlLineEdit = new QLineEdit(downloadUrlDialog);
        urlLineEdit->setObjectName(QString::fromUtf8("urlLineEdit"));
        urlLineEdit->setGeometry(QRect(50, 40, 381, 21));
        downloadUrlBtn = new QPushButton(downloadUrlDialog);
        downloadUrlBtn->setObjectName(QString::fromUtf8("downloadUrlBtn"));
        downloadUrlBtn->setGeometry(QRect(170, 80, 80, 21));

        retranslateUi(downloadUrlDialog);

        QMetaObject::connectSlotsByName(downloadUrlDialog);
    } // setupUi

    void retranslateUi(QDialog *downloadUrlDialog)
    {
        downloadUrlDialog->setWindowTitle(QCoreApplication::translate("downloadUrlDialog", "Http download", nullptr));
        urlLabel->setText(QCoreApplication::translate("downloadUrlDialog", "Url:", nullptr));
        downloadUrlBtn->setText(QCoreApplication::translate("downloadUrlDialog", "Download", nullptr));
    } // retranslateUi

};

namespace Ui {
    class downloadUrlDialog: public Ui_downloadUrlDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADURLDIALOG_H
