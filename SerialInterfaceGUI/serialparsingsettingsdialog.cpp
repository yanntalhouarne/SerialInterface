#include "serialparsingsettingsdialog.h"
#include "ui_parsingSettingsDialog.h"

serialParsingSettingsDialog::serialParsingSettingsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::parsingSettingsDialog)
{
    ui->setupUi(this);

    setWindowTitle("Parsing settings");

    // DATA FORMAT COMBO BOX INIT
    ui->dataFormatComboBox->addItem("ASCII");
    ui->dataFormatComboBox->addItem("raw");
    ui->dataFormatComboBox->setCurrentIndex(0);


    // NUMBER OF BYTES COMBO BOX INIT
    ui->nbrBytesComboBox->addItem("1");
    ui->nbrBytesComboBox->addItem("2");
    ui->nbrBytesComboBox->addItem("4");
    ui->nbrBytesComboBox->setCurrentIndex(1);
    //ui->nbrBytesComboBox->setDisabled(1);

    applyParsingSettings();

    connect(ui->dataFormatComboBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &serialParsingSettingsDialog::showByteNbr);
    connect(ui->parsingSettingsApplyButton, &QPushButton::clicked,
            this, &serialParsingSettingsDialog::applyParsingSettings);
}

serialParsingSettingsDialog::~serialParsingSettingsDialog()
{
    delete ui;
}

void serialParsingSettingsDialog::applyParsingSettings()
{
   m_parsingSettings.dataFormat = ui->dataFormatComboBox->currentIndex();
   m_parsingSettings.byteNbr = ui->nbrBytesComboBox->currentText().toUInt();
   hide();
}

void serialParsingSettingsDialog::showByteNbr(int idx)
{
    if (idx == 1) // RAW
    {
        ui->nbrBytesComboBox->setEnabled(1);
    }
    else // ASCII
    {
        ui->nbrBytesComboBox->setCurrentIndex(0);
        ui->nbrBytesComboBox->setDisabled(1);
    }
}

/* GET CURRENT SETTINGS CLASS */
serialParsingSettingsDialog::parsingSettings serialParsingSettingsDialog::getParsingSettings() const
{
    return m_parsingSettings;
}

