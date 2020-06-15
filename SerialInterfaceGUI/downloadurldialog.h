#ifndef DOWNLOADURLDIALOG_H
#define DOWNLOADURLDIALOG_H

#include <QDialog>
#include <QDir>

#include "downloadmanager.h"
#include "openfilefailuredialog.h"

namespace Ui {
class downloadUrlDialog;
}

class downloadUrlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit downloadUrlDialog(QWidget *parent = nullptr);
    ~downloadUrlDialog();

    OpenFileFailureDialog * m_openFileFailureDialog = nullptr;

    QString getUrlFileName();

private:
    Ui::downloadUrlDialog *ui;
    downloadManager * m_downloadManager = nullptr;

signals:
    void fileDownloadSuccess();


private slots:
    void downloadFile();
    void closeDialog();

};

#endif // DOWNLOADURLDIALOG_H
