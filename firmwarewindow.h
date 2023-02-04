#ifndef FIRMWAREWINDOW_H
#define FIRMWAREWINDOW_H

#include <QMainWindow>
#include "modules/connection.h"

namespace Ui {
class FirmwareWindow;
}

class FirmwareWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FirmwareWindow(QWidget *parent = nullptr);
    ~FirmwareWindow();

private:
    Ui::FirmwareWindow *ui;

    Connection* check;

signals:
    void settingWindow();
public slots:
    void on_backButton_clicked();
    void changeConnection(bool result);
};

#endif // FIRMWAREWINDOW_H
