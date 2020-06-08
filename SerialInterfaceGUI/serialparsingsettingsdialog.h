#ifndef SERIALPARSINGSETTINGSDIALOG_H
#define SERIALPARSINGSETTINGSDIALOG_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QPushButton>
#define ASCII 0
#define RAW 1
#define STM32_BOOTLOADER_MODE 2

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
        enum dataFormatEnum {ascii, raw};
        unsigned int dataFormat;
        unsigned int byteNbr;
    };

    parsingSettings getParsingSettings() const; // returns a copy of pSettings
    unsigned int getDataFormat();

    //void setDataFormatSpinBox(int parsingSettings);

private slots:
    void applyParsingSettings();
    void showByteNbr(int idx);

public slots:
    void setParsingSettings(int parsingSetting);


private:
    Ui::parsingSettingsDialog * ui = nullptr;
    parsingSettings m_parsingSettings;



};

#endif // SERIALPARSINGSETTINGSDIALOG_H
