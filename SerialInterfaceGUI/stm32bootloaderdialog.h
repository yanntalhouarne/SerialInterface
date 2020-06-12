#ifndef STM32BOOTLOADERDIALOG_H
#define STM32BOOTLOADERDIALOG_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QByteArray>
#include <QString>

#include "openfilefailuredialog.h"

namespace Ui {
class stm32bootloaderDialog;
}

class stm32bootloaderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit stm32bootloaderDialog(QWidget *parent = nullptr);
    ~stm32bootloaderDialog();

    class hexFileSettings
    {
    public:
        explicit hexFileSettings() {};
        hexFileSettings (const hexFileSettings &old_obj) {adrress = old_obj.adrress; length = old_obj.length; fileName = old_obj.fileName; fileOpened = old_obj.fileOpened;} // copy constructor
        QFile hexFile;
        QString fileName;
        bool fileOpened = 0;
        long adrress;
        unsigned int length;
        QByteArray getDataFromHexFile();

    };

public:
    bool isFileOpened();
    void closeHexFile();
    bool openHexFile();
    long getAddress();
    unsigned int getLength();
    hexFileSettings getHexSettings();


private slots:
    void applyHexFileSettings();
    void selectHexFile();

private:
    Ui::stm32bootloaderDialog *ui;
    hexFileSettings m_hexFileSettings;
    OpenFileFailureDialog * m_openFileFailureDialog = nullptr;
};

#endif // STM32BOOTLOADERDIALOG_H
