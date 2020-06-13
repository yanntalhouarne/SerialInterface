#include "bootloaderinfodialog.h"
#include "ui_bootloaderinfodialog.h"

bootloaderInfoDialog::bootloaderInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bootloaderInfoDialog)
{
    ui->setupUi(this);
    ui->plainTextEdit->setReadOnly(true);
}

bootloaderInfoDialog::~bootloaderInfoDialog()
{
    delete ui;
}
