#include "downloadurldialog.h"
#include "ui_downloadurldialog.h"


downloadUrlDialog::downloadUrlDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::downloadUrlDialog)
{
    ui->setupUi(this);
    m_downloadManager = new downloadManager();

    m_openFileFailureDialog = new OpenFileFailureDialog(this);

    connect(ui->downloadUrlBtn, &QPushButton::clicked, this, &downloadUrlDialog::downloadFile);
    connect(m_downloadManager, &downloadManager::finishedSignal, this, &downloadUrlDialog::closeDialog);
}

downloadUrlDialog::~downloadUrlDialog()
{
    delete ui;
}

QString downloadUrlDialog::getUrlFileName()
{
    return m_downloadManager->getFileName();
}

void downloadUrlDialog::downloadFile()
{
    QUrl url = QUrl::fromEncoded(ui->urlLineEdit->text().toLocal8Bit());
    m_downloadManager->doDownload(url);
}

void downloadUrlDialog::closeDialog()
{
    if (m_downloadManager->getErr())
    {
        m_openFileFailureDialog->setLabel("Could not download the file.");
    }
    else
    {
        m_openFileFailureDialog->setLabel("File succesfully downloaded.");
    }
    m_openFileFailureDialog->setModal(true);
    m_openFileFailureDialog->show();
    emit fileDownloadSuccess();
    close();
}
