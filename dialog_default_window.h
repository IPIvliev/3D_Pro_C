#ifndef DIALOG_DEFAULT_WINDOW_H
#define DIALOG_DEFAULT_WINDOW_H

#include <QDialog>

namespace Ui {
class DefaultDialog;
}

class DefaultDialog : public QDialog {
    Q_OBJECT

public:
    explicit DefaultDialog(QWidget *parent = nullptr);
    ~DefaultDialog();

private slots:
    void on_yesButton_clicked();

    void on_noButton_clicked();

private:
    Ui::DefaultDialog *ui;
};

#endif // DIALOG_DEFAULT_WINDOW_H
