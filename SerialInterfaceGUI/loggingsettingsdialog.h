#ifndef LOGGINGSETTINGSDIALOG_H
#define LOGGINGSETTINGSDIALOG_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QPushButton>
#include <QTextStream>
#include <QCheckBox>
#include <QIODevice>

#include "openfilefailuredialog.h"

namespace Ui {
class LoggingSettingsDialog;
}

class LoggingSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoggingSettingsDialog(QWidget *parent = nullptr);
    ~LoggingSettingsDialog();

    struct loggingSettings
    {
        QFile loggingFile;
        QString fileName;
        bool loggingEnabled = 0;
        bool fileOpened = 0;
    };

    loggingSettings getLoggingSettings() const; // returns a copy of pSettings
    void appendToFile(QByteArray baAscii);
    bool isLoggingEnabled();
    QFile & getFile();
    void closeFile();
    bool openFile();
    bool isFileOpened();

private slots:
    void applyLoggingSettings();
    void selectFile();

public slots:
    void updateLoggingCheckBox();

private:
    Ui::LoggingSettingsDialog * ui = nullptr;
    loggingSettings m_loggingSettings;
    OpenFileFailureDialog * m_openFileFailureDialog = nullptr;


};

#endif // LOGGINGSETTINGSDIALOG_H
