#include "openfilefailuredialog.h"
#include "ui_openfilefailuredialog.h"

OpenFileFailureDialog::OpenFileFailureDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenFileFailureDialog)
{
    ui->setupUi(this);

    setWindowTitle("File opening failure");

    connect(ui->openFileFailureButton, &QPushButton::clicked, this, &OpenFileFailureDialog::closeDialog);
}

OpenFileFailureDialog::~OpenFileFailureDialog()
{
    delete ui;
}

void OpenFileFailureDialog::closeDialog()
{
    close();
}
