#ifndef SERIALPARSINGSETTINGSDIALOG_H
#define SERIALPARSINGSETTINGSDIALOG_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QPushButton>

QT_BEGIN_NAMESPACE

namespace Ui {class parsingSettingsDialog;}

class serialParsingSettingsDialog : public QDialog
{

    Q_OBJECT

public:
    serialParsingSettingsDialog(QWidget *parent = nullptr);
    ~serialParsingSettingsDialog();

public:
    struct parsingSettings
    {
        enum dataFormatEnum { ascii, raw};
        unsigned int dataFormat;
        unsigned int byteNbr;
    };

    parsingSettings getParsingSettings() const; // returns a copy of pSettings

private slots:
    void applyParsingSettings();
    void showByteNbr(int idx);

private:
    Ui::parsingSettingsDialog * ui = nullptr;
    parsingSettings m_parsingSettings;



};

#endif // SERIALPARSINGSETTINGSDIALOG_H
