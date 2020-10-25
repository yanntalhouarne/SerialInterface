/********************************************************************************
** Form generated from reading UI file 'genericdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERICDIALOG_H
#define UI_GENERICDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_genericDialog
{
public:
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *genericDialog)
    {
        if (genericDialog->objectName().isEmpty())
            genericDialog->setObjectName(QString::fromUtf8("genericDialog"));
        genericDialog->resize(286, 133);
        label = new QLabel(genericDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 251, 21));
        label->setAlignment(Qt::AlignCenter);
        widget = new QWidget(genericDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 80, 168, 23));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        retranslateUi(genericDialog);

        QMetaObject::connectSlotsByName(genericDialog);
    } // setupUi

    void retranslateUi(QDialog *genericDialog)
    {
        genericDialog->setWindowTitle(QCoreApplication::translate("genericDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("genericDialog", "File already exists. Do you want to overwrite it?", nullptr));
        pushButton->setText(QCoreApplication::translate("genericDialog", "Yes", nullptr));
        pushButton_2->setText(QCoreApplication::translate("genericDialog", "No", nullptr));
    } // retranslateUi

};

namespace Ui {
    class genericDialog: public Ui_genericDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERICDIALOG_H
