#include "loggingsettingsdialog.h"
#include "ui_loggingsettingsdialog.h"

LoggingSettingsDialog::LoggingSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoggingSettingsDialog)
{
    ui->setupUi(this);

    ui->loggingEnabledCheckbox->setChecked(0);

    connect(ui->logSettingsAppplyButton, &QPushButton::clicked,    this, &LoggingSettingsDialog::applyLoggingSettings);
    connect(ui->selectFile,              &QPushButton::clicked,    this, &LoggingSettingsDialog::selectFile);
    //connect(ui->loggingEnabledCheckbox,  &QCheckBox::stateChanged, this, &LoggingSettingsDialog::setLoggingFlag);
}

LoggingSettingsDialog::~LoggingSettingsDialog()
{
    delete ui;
}

void LoggingSettingsDialog::applyLoggingSettings()
{
    if(ui->loggingEnabledCheckbox->isChecked())
    {
        m_loggingSettings.loggingEnabled = 1;
    }
    else
    {
        m_loggingSettings.loggingEnabled = 0;
    }

    if (!m_loggingSettings.fileOpened)
    {
        if (!openFile())
        {
            QDialog FileOpeningErrDiag;
            QLabel FileOpeningeErrLabel("Could not open file.", &FileOpeningErrDiag);
        }
    }

    hide();
}

void LoggingSettingsDialog::appendToFile(QByteArray baAscii)
{
    QFile & fileRef = getFile();
    QTextStream out(&fileRef);
    out << baAscii;
}

void LoggingSettingsDialog::updateLoggingCheckBox()
{
    if(!m_loggingSettings.loggingEnabled)
    {
       ui->loggingEnabledCheckbox->setChecked(0);
    }
    else
    {
        ui->loggingEnabledCheckbox->setChecked(1);
    }
}

bool LoggingSettingsDialog::isLoggingEnabled()
{
    return  m_loggingSettings.loggingEnabled;
}

QFile & LoggingSettingsDialog::getFile()
{
    return m_loggingSettings.loggingFile;
}

void LoggingSettingsDialog::selectFile()
{
    m_loggingSettings.fileName = QFileDialog::getOpenFileName(this,
        tr("Select file"), "./Logs", tr("CSV Files (*.csv)"));
    ui->fileLineEdit->setText(m_loggingSettings.fileName);
}

bool LoggingSettingsDialog::isFileOpened()
{
    return m_loggingSettings.fileOpened;
}

void LoggingSettingsDialog::closeFile()
{
    //ui->loggingEnabledCheckbox->setChecked(0);
    m_loggingSettings.fileOpened = 0;
    if (m_loggingSettings.loggingFile.isOpen())
        m_loggingSettings.loggingFile.close();
}

bool LoggingSettingsDialog::openFile()
{
    if (!m_loggingSettings.loggingFile.isOpen())
    {
        m_loggingSettings.loggingFile.setFileName(m_loggingSettings.fileName);
        if(m_loggingSettings.loggingFile.open(QIODevice::ReadWrite) && (!isFileOpened()))
            m_loggingSettings.fileOpened = 1;
        return 1;
    }
    else
    {
        return 0;
    }
}

