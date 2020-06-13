#ifndef BOOTLOADERINFODIALOG_H
#define BOOTLOADERINFODIALOG_H

#include <QDialog>

namespace Ui {
class bootloaderInfoDialog;
}

class bootloaderInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit bootloaderInfoDialog(QWidget *parent = nullptr);
    ~bootloaderInfoDialog();

private:
    Ui::bootloaderInfoDialog *ui;
};

#endif // BOOTLOADERINFODIALOG_H
