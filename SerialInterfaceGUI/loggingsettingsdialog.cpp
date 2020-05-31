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
    connect(ui->loggingEnabledCheckbox,  &QCheckBox::stateChanged, this, &LoggingSettingsDialog::setLoggingFlag);
}

LoggingSettingsDialog::~LoggingSettingsDialog()
{
    delete ui;
}

void LoggingSettingsDialog::applyLoggingSettings()
{
    //m_loggingSettings.loggingFile.write("123");
    //m_loggingSettings.loggingFile.close();
    hide();
}

void LoggingSettingsDialog::appendToFile(QByteArray baAscii)
{
    QFile & fileRef = getFile();
    QTextStream out(&fileRef);
    out << baAscii;
}

void LoggingSettingsDialog::setLoggingFlag()
{
    if (ui->loggingEnabledCheckbox->isChecked())
        m_loggingSettings.loggingON = 1;
    else
        m_loggingSettings.loggingON = 0;
}

bool LoggingSettingsDialog::isLoggingOn()
{
    return  m_loggingSettings.loggingON;
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

    m_loggingSettings.loggingFile.setFileName(m_loggingSettings.fileName);
    m_loggingSettings.loggingFile.open(QIODevice::ReadWrite);
}

void LoggingSettingsDialog::closeFile()
{
    ui->loggingEnabledCheckbox->setChecked(0);
    m_loggingSettings.loggingFile.close();
}

void LoggingSettingsDialog::startLoggingFile()
{
    if (m_loggingSettings.loggingFile.isOpen())
        ui->loggingEnabledCheckbox->setChecked(1);
}

