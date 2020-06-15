#include "stm32bootloaderdialog.h"
#include "ui_stm32bootloaderdialog.h"

stm32bootloaderDialog::stm32bootloaderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stm32bootloaderDialog)
{
    ui->setupUi(this);

    setWindowTitle("Select hex file");

    // FILE OPEN FAILED DIALOG
    m_openFileFailureDialog = new OpenFileFailureDialog(this);

    // GET FILE FROM URL DIALOG
    m_downloadUrlDialog = new downloadUrlDialog(this);

    ui->adressLineEdit->setText("08000000");





    connect(ui->hexFilePathApplyBtn,    &QPushButton::clicked,                      this,                 &stm32bootloaderDialog::applyHexFileSettings);
    connect(ui->hexFilePathSelectBtn,   &QPushButton::clicked,                      this,                 &stm32bootloaderDialog::selectHexFile);
    connect(ui->downloadUrlPushbutton,  &QPushButton::clicked,                      m_downloadUrlDialog,  &downloadUrlDialog::show);
    connect(m_downloadUrlDialog,        &downloadUrlDialog::fileDownloadSuccess,    this,                 &stm32bootloaderDialog::getFileFromUrl);

}

stm32bootloaderDialog::~stm32bootloaderDialog()
{
    delete ui;
}

bool stm32bootloaderDialog::openHexFile()
{
    closeHexFile();
    if (!m_hexFileSettings.hexFile.isOpen())
    {
        if(m_hexFileSettings.hexFile.open(QIODevice::ReadOnly) && (!isFileOpened()))
        {
            m_hexFileSettings.fileOpened = 1;
            m_hexFileSettings.length = m_hexFileSettings.hexFile.size();
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

void stm32bootloaderDialog::selectHexFile()
{
    m_hexFileSettings.fileName = QFileDialog::getOpenFileName(this,
        tr("Select file"), ".", tr("BIN Files (*.bin)"));
    m_hexFileSettings.hexFile.setFileName(m_hexFileSettings.fileName);
    ui->hexFilePathLineEdit->setText(m_hexFileSettings.fileName);
}

void stm32bootloaderDialog::getFileFromUrl()
{
    m_hexFileSettings.fileName = m_downloadUrlDialog->getUrlFileName();
    m_hexFileSettings.hexFile.setFileName(m_hexFileSettings.fileName);
    ui->hexFilePathLineEdit->setText(m_hexFileSettings.fileName);
}

bool stm32bootloaderDialog::isFileOpened()
{
    return m_hexFileSettings.fileOpened;
}

void stm32bootloaderDialog::closeHexFile()
{
    //ui->loggingEnabledCheckbox->setChecked(0);
    m_hexFileSettings.fileOpened = 0;
    if (m_hexFileSettings.hexFile.isOpen())
        m_hexFileSettings.hexFile.close();
}

void stm32bootloaderDialog::applyHexFileSettings()
{
    if (!openHexFile())
    {
        m_openFileFailureDialog->show();
    }
    else
    {
        // get address from lineEdit
        auto addrString = ui->adressLineEdit->text();
        bool ok;
        m_hexFileSettings.adrress = addrString.toLong(&ok, 16);
        hide();
    }

}

QByteArray stm32bootloaderDialog::hexFileSettings::getDataFromHexFile()
{
    QByteArray data;

    if (fileOpened)
    {
        QFile m_hexFile(fileName);
        m_hexFile.open(QIODevice::ReadOnly);
        // get data from .hex file to byte array
        //if (m_hexFileSettings.length <= 1000000)
        data = m_hexFile.read(1000000); // 1Mb max
        // get data length
        length = data.size();
    }
    else
    {
        // file not opened
    }

    return data;
}

long stm32bootloaderDialog::getAddress()
{
    return m_hexFileSettings.adrress;
}

unsigned int stm32bootloaderDialog::getLength()
{
    return m_hexFileSettings.length;
}

stm32bootloaderDialog::hexFileSettings stm32bootloaderDialog::getHexSettings()
{
    return m_hexFileSettings;
}
