#ifndef LOGGINGSETTINGSDIALOG_H
#define LOGGINGSETTINGSDIALOG_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QPushButton>
#include <QTextStream>
#include <QCheckBox>
#include <QIODevice>

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
        bool loggingON = 0;
    };

    loggingSettings getLoggingSettings() const; // returns a copy of pSettings
    void appendToFile(QByteArray baAscii);
    bool isLoggingOn();
    QFile & getFile();
    void closeFile();
    void startLoggingFile();

private slots:
    void applyLoggingSettings();
    void selectFile();
    void setLoggingFlag();


private:
    Ui::LoggingSettingsDialog * ui = nullptr;
    loggingSettings m_loggingSettings;


};

#endif // LOGGINGSETTINGSDIALOG_H
