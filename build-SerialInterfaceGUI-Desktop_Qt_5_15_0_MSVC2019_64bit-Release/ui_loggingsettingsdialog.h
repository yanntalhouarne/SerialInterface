/********************************************************************************
** Form generated from reading UI file 'loggingsettingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGGINGSETTINGSDIALOG_H
#define UI_LOGGINGSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoggingSettingsDialog
{
public:
    QPushButton *logSettingsAppplyButton;
    QCheckBox *loggingEnabledCheckbox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *fileLineEdit;
    QPushButton *selectFile;

    void setupUi(QDialog *LoggingSettingsDialog)
    {
        if (LoggingSettingsDialog->objectName().isEmpty())
            LoggingSettingsDialog->setObjectName(QString::fromUtf8("LoggingSettingsDialog"));
        LoggingSettingsDialog->resize(337, 93);
        logSettingsAppplyButton = new QPushButton(LoggingSettingsDialog);
        logSettingsAppplyButton->setObjectName(QString::fromUtf8("logSettingsAppplyButton"));
        logSettingsAppplyButton->setGeometry(QRect(250, 60, 61, 21));
        loggingEnabledCheckbox = new QCheckBox(LoggingSettingsDialog);
        loggingEnabledCheckbox->setObjectName(QString::fromUtf8("loggingEnabledCheckbox"));
        loggingEnabledCheckbox->setGeometry(QRect(30, 60, 72, 19));
        widget = new QWidget(LoggingSettingsDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 20, 301, 24));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        fileLineEdit = new QLineEdit(widget);
        fileLineEdit->setObjectName(QString::fromUtf8("fileLineEdit"));

        horizontalLayout->addWidget(fileLineEdit);

        selectFile = new QPushButton(widget);
        selectFile->setObjectName(QString::fromUtf8("selectFile"));
        selectFile->setMaximumSize(QSize(31, 21));

        horizontalLayout->addWidget(selectFile);


        retranslateUi(LoggingSettingsDialog);

        QMetaObject::connectSlotsByName(LoggingSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *LoggingSettingsDialog)
    {
        LoggingSettingsDialog->setWindowTitle(QCoreApplication::translate("LoggingSettingsDialog", "Dialog", nullptr));
        logSettingsAppplyButton->setText(QCoreApplication::translate("LoggingSettingsDialog", "Apply", nullptr));
        loggingEnabledCheckbox->setText(QCoreApplication::translate("LoggingSettingsDialog", "enabled", nullptr));
        label->setText(QCoreApplication::translate("LoggingSettingsDialog", "File Path", nullptr));
        selectFile->setText(QCoreApplication::translate("LoggingSettingsDialog", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoggingSettingsDialog: public Ui_LoggingSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGGINGSETTINGSDIALOG_H
