#ifndef ACCOUNTPRINTWINDOW_H
#define ACCOUNTPRINTWINDOW_H

#include <QMainWindow>

namespace Ui {
class AccountPrintWindow;
}

class AccountPrintWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AccountPrintWindow(QWidget *parent = nullptr);
    ~AccountPrintWindow();

private slots:
    void on_backButton_clicked();
    void changeConnection(bool result);

private:
    Ui::AccountPrintWindow *ui;

signals:
    void choosePrintWindow();
};

#endif // ACCOUNTPRINTWINDOW_H
