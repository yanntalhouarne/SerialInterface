#ifndef PORTCONNFAILUREDIALOG_H
#define PORTCONNFAILUREDIALOG_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class PortConnFailureDialog;
}

class PortConnFailureDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PortConnFailureDialog(QWidget *parent = nullptr);
    ~PortConnFailureDialog();

    void setTextLabel(const QString & errStrg);


private:
    Ui::PortConnFailureDialog *ui;
};

#endif // PORTCONNFAILUREDIALOG_H
