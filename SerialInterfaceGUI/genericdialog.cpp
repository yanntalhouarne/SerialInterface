#include "genericdialog.h"
#include "ui_genericdialog.h"

genericDialog::genericDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::genericDialog)
{
    ui->setupUi(this);
}

genericDialog::~genericDialog()
{
    delete ui;
}

void genericDialog::setLabel(const QString & strg)
{
    ui->label->setText(strg);
}
