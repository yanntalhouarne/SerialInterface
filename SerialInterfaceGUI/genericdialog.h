#ifndef GENERICDIALOG_H
#define GENERICDIALOG_H

#include <QDialog>

namespace Ui {
class genericDialog;
}

class genericDialog : public QDialog
{
    Q_OBJECT

public:
    explicit genericDialog(QWidget *parent = nullptr);
    ~genericDialog();
    void setLabel(const QString & strg);

private:
    Ui::genericDialog *ui;
};

#endif // GENERICDIALOG_H
