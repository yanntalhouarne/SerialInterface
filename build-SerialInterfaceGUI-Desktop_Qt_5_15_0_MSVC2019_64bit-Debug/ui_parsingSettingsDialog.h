/********************************************************************************
** Form generated from reading UI file 'parsingSettingsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARSINGSETTINGSDIALOG_H
#define UI_PARSINGSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_parsingSettingsDialog
{
public:
    QComboBox *dataFormatComboBox;
    QComboBox *nbrBytesComboBox;
    QLabel *dataFormatLabel;
    QLabel *nbrBytesLabel;
    QPushButton *parsingSettingsApplyButton;

    void setupUi(QDialog *parsingSettingsDialog)
    {
        if (parsingSettingsDialog->objectName().isEmpty())
            parsingSettingsDialog->setObjectName(QString::fromUtf8("parsingSettingsDialog"));
        parsingSettingsDialog->resize(258, 128);
        dataFormatComboBox = new QComboBox(parsingSettingsDialog);
        dataFormatComboBox->setObjectName(QString::fromUtf8("dataFormatComboBox"));
        dataFormatComboBox->setGeometry(QRect(100, 10, 141, 22));
        nbrBytesComboBox = new QComboBox(parsingSettingsDialog);
        nbrBytesComboBox->setObjectName(QString::fromUtf8("nbrBytesComboBox"));
        nbrBytesComboBox->setGeometry(QRect(100, 40, 72, 22));
        dataFormatLabel = new QLabel(parsingSettingsDialog);
        dataFormatLabel->setObjectName(QString::fromUtf8("dataFormatLabel"));
        dataFormatLabel->setGeometry(QRect(30, 10, 61, 16));
        nbrBytesLabel = new QLabel(parsingSettingsDialog);
        nbrBytesLabel->setObjectName(QString::fromUtf8("nbrBytesLabel"));
        nbrBytesLabel->setGeometry(QRect(10, 40, 81, 16));
        parsingSettingsApplyButton = new QPushButton(parsingSettingsDialog);
        parsingSettingsApplyButton->setObjectName(QString::fromUtf8("parsingSettingsApplyButton"));
        parsingSettingsApplyButton->setGeometry(QRect(90, 80, 80, 21));

        retranslateUi(parsingSettingsDialog);

        QMetaObject::connectSlotsByName(parsingSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *parsingSettingsDialog)
    {
        parsingSettingsDialog->setWindowTitle(QCoreApplication::translate("parsingSettingsDialog", "Dialog", nullptr));
        dataFormatLabel->setText(QCoreApplication::translate("parsingSettingsDialog", "Data format", nullptr));
        nbrBytesLabel->setText(QCoreApplication::translate("parsingSettingsDialog", "Number of bytes", nullptr));
        parsingSettingsApplyButton->setText(QCoreApplication::translate("parsingSettingsDialog", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class parsingSettingsDialog: public Ui_parsingSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARSINGSETTINGSDIALOG_H
