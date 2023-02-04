#ifndef SERVICEWINDOW_H
#define SERVICEWINDOW_H

#include <QMainWindow>
#include "zwindow.h"
#include "vatwindow.h"

namespace Ui {
class ServiceWindow;
}

class ServiceWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServiceWindow(QWidget *parent = nullptr);
    ~ServiceWindow();

private:
    Ui::ServiceWindow *ui;

    ZWindow *zWindow;
    VatWindow *vatWindow;

    bool led = false;
    bool vat = false;

signals:
    void mainWindow();

private slots:
    void on_backButton_clicked();
    void on_moveButton_clicked();
    void on_vatButton_clicked();
    void on_clearButton_clicked();
    void on_toggleButton_clicked();
    void turnoffLed();
    void turnoffVat();
    void changeConnection(bool result);
};

#endif // SERVICEWINDOW_H
