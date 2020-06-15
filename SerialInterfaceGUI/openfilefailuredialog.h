#ifndef OPENFILEFAILUREDIALOG_H
#define OPENFILEFAILUREDIALOG_H
#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class OpenFileFailureDialog;
}

class OpenFileFailureDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OpenFileFailureDialog(QWidget *parent = nullptr);
    ~OpenFileFailureDialog();
    void setLabel(const QString & strgLabel);

private slots:
    void closeDialog();

private:
    Ui::OpenFileFailureDialog *ui;
};

#endif // OPENFILEFAILUREDIALOG_H
