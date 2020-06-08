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

    ui->adressLineEdit->setText("08000000");


    connect(ui->hexFilePathApplyBtn,    &QPushButton::clicked,    this,     &stm32bootloaderDialog::applyHexFileSettings);
    connect(ui->hexFilePathSelectBtn,   &QPushButton::clicked,    this,     &stm32bootloaderDialog::selectHexFile);
}

stm32bootloaderDialog::~stm32bootloaderDialog()
{
    delete ui;
}

bool stm32bootloaderDialog::openHexFile()
{
    if (!m_hexFileSettings.hexFile.isOpen())
    {
        m_hexFileSettings.hexFile.setFileName(m_hexFileSettings.fileName);
        if(m_hexFileSettings.hexFile.open(QIODevice::ReadOnly) && (!isFileOpened()))
        {
            m_hexFileSettings.fileOpened = 1;
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

    if (!m_hexFileSettings.fileOpened)
    {
        if (!openHexFile())
        {
            m_openFileFailureDialog->show();
        }
        else
        {
            hide();
        }
    }
    else
    {
        // file already open
        hide();
    }
}

QByteArray stm32bootloaderDialog::getDataFromHexFile()
{
    QByteArray data;

    if (m_hexFileSettings.fileOpened)
    {
        // get address from lineEdit
        auto addrString = ui->adressLineEdit->text();
        bool ok;
        m_hexFileSettings.adrress = addrString.toLong(&ok, 16);
        // get data from .hex file to byte array
        if (m_hexFileSettings.length <= 1000000)
            data = m_hexFileSettings.hexFile.read(1000000); // 1Mb max
        // get data length
        m_hexFileSettings.length = data.size();
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
