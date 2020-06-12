#include "progressbardialog.h"
#include "ui_progressbardialog.h"

progressBarDialog::progressBarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::progressBarDialog)
{
    ui->setupUi(this);

    ui->progressBar->setValue(0);

    connect(ui->pushButton, &QPushButton::clicked, this, &progressBarDialog::hide);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &progressBarDialog::setAbortFlag);
}

progressBarDialog::~progressBarDialog()
{
    delete ui;
}

void progressBarDialog::setProgressBarRange(unsigned int range)
{
    ui->progressBar->setRange(0, range);
}

void progressBarDialog::setProgressBarValue(unsigned int value)
{
    ui->progressBar->setValue(value);
}

void progressBarDialog::disableDoneButton()
{
     ui->pushButton->setDisabled(1);
}

void progressBarDialog::enableDoneButton()
{
     ui->pushButton->setDisabled(0);
}

void progressBarDialog::disableAbortButton()
{
     ui->pushButton_2->setDisabled(1);
}

void progressBarDialog::enableAbortButton()
{
     ui->pushButton_2->setDisabled(0);
}

void progressBarDialog::setLabel(const QString & text)
{
     ui->label->setText(text);
}

bool progressBarDialog::getAbortFlag()
{
    return abortFlag;
}

void progressBarDialog::clearAbortFlag()
{
    abortFlag = 0;
}

void progressBarDialog::setAbortFlag()
{
    abortFlag = 1;
}

