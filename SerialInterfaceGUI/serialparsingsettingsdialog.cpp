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
    ui->dataFormatComboBox->setItemData(0, "Received data is in ASCII format.", Qt::ToolTipRole);
    ui->dataFormatComboBox->addItem("raw bytes");
    ui->dataFormatComboBox->setItemData(1, "Received bytes are printed as they arrived.", Qt::ToolTipRole);
    ui->dataFormatComboBox->addItem("raw bytes w/ checksum");
    ui->dataFormatComboBox->setItemData(2, "Received data has a CR (13) character and checksum.", Qt::ToolTipRole);
    ui->dataFormatComboBox->addItem("STM32 bootloader");
    ui->dataFormatComboBox->setItemData(3, "Supported commands:\n     -INIT (0x7F)\n     -GET_ID (0x02)\n     -ERASE_SECTORS_0_TO_4 (0x98)\n     -UPLOAD_BIN_FILE (0x99)", Qt::ToolTipRole);
    m_parsingSettings.dataFormat = ASCII;


    // NUMBER OF BYTES COMBO BOX INIT
    ui->nbrBytesComboBox->addItem("1");
    ui->nbrBytesComboBox->setItemData(0, "-data format: [DATA][13][CS]\n-CS = [DATA0]^[13])", Qt::ToolTipRole);
    ui->nbrBytesComboBox->addItem("2");
    ui->nbrBytesComboBox->setItemData(1, "-data format: [LSB][MSB][13][CS]\n-CS = [LSB]^[MSB]^[13])", Qt::ToolTipRole);
    ui->nbrBytesComboBox->addItem("4");
    ui->nbrBytesComboBox->setItemData(2, "-data format: [LSB][DATA1][DATA2][MSB][13][CS]\n-CS = [LSB]^[DATA1]^[DATA2]^[MSB]^[13])", Qt::ToolTipRole);
    ui->nbrBytesComboBox->setCurrentIndex(1);
    ui->nbrBytesComboBox->setDisabled(1);

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

QPushButton * serialParsingSettingsDialog::getApplyButton()
{
    return ui->parsingSettingsApplyButton;
}

void serialParsingSettingsDialog::applyParsingSettings()
{
   m_parsingSettings.dataFormat = ui->dataFormatComboBox->currentIndex();
   m_parsingSettings.byteNbr = ui->nbrBytesComboBox->currentText().toUInt();
   hide();
}

void serialParsingSettingsDialog::showByteNbr(int idx)
{
    if (idx == RAW_DATA_CHECKSUM) // RAW
    {
        ui->nbrBytesComboBox->setEnabled(1);
    }
    else // ASCII or STM32_BOOTLOADER_MODE
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

unsigned int serialParsingSettingsDialog::getDataFormat()
{
    return m_parsingSettings.dataFormat;
}

unsigned int serialParsingSettingsDialog::getNbrBytes()
{
    return m_parsingSettings.byteNbr;
}

void serialParsingSettingsDialog::setParsingSettings(int parsingSetting)
{
    switch (parsingSetting)
    {
        case ASCII:
        {
            m_parsingSettings.dataFormat = ASCII;
            ui->dataFormatComboBox->setCurrentIndex(ASCII);
            break;
        }
        case RAW_BYTE_FORMAT:
        {
            m_parsingSettings.dataFormat = RAW_BYTE_FORMAT;
            ui->dataFormatComboBox->setCurrentIndex(RAW_BYTE_FORMAT);
            break;
        }
        case RAW_DATA_CHECKSUM:
        {
            m_parsingSettings.dataFormat = RAW_DATA_CHECKSUM;
            ui->dataFormatComboBox->setCurrentIndex(RAW_DATA_CHECKSUM);
            break;
        }
        case STM32_BOOTLOADER_MODE:
        {
            m_parsingSettings.dataFormat = STM32_BOOTLOADER_MODE;
            ui->dataFormatComboBox->setCurrentIndex(STM32_BOOTLOADER_MODE);
            break;
        }
    } // end of: switch (parsingSettings)
}

//void serialParsingSettingsDialog::setDataFormatSpinBox(int parsingSettings)
//{
//   if (parsingSettings == ASCII)
//   {
//        ui->dataFormatComboBox->setCurrentIndex(ASCII);
//   }
//   else if (parsingSettings == RAW)
//   {
//        ui->dataFormatComboBox->setCurrentIndex(RAW);
//   }
//}

