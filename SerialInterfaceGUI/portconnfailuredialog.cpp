#include "portconnfailuredialog.h"
#include "ui_portconnfailuredialog.h"

PortConnFailureDialog::PortConnFailureDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PortConnFailureDialog)
{
    ui->setupUi(this);

    setWindowTitle("Port connection failure");

    connect(ui->portConnFailureButton, &QPushButton::clicked, this, &PortConnFailureDialog::hide);
}

PortConnFailureDialog::~PortConnFailureDialog()
{
    delete ui;
}

void PortConnFailureDialog::setTextLabel(const QString & errStrg)
{
    ui->portConnFailureLabel->setText(errStrg);
}
