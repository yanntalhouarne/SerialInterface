#ifndef PROGRESSBARDIALOG_H
#define PROGRESSBARDIALOG_H

#include <QDialog>

namespace Ui {
class progressBarDialog;
}

class progressBarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit progressBarDialog(QWidget *parent = nullptr);
    ~progressBarDialog();

    void setProgressBarRange(unsigned int range);
    void setProgressBarValue(unsigned int value);
    void disableDoneButton();
    void enableDoneButton();
    void disableAbortButton();
    void enableAbortButton();
    void setLabel(const QString & text);
    bool getAbortFlag();
    void clearAbortFlag();



private slots:
    void setAbortFlag();

private:
    Ui::progressBarDialog *ui;
    bool abortFlag = 0;
};

#endif // PROGRESSBARDIALOG_H
