#ifndef WIFIWINDOW_H
#define WIFIWINDOW_H

#include <QMainWindow>

namespace Ui {
class WifiWindow;
}

class WifiWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WifiWindow(QWidget *parent = nullptr);
    ~WifiWindow();

private:
    Ui::WifiWindow *ui;

signals:
    void settingWindow();
private slots:
    void on_backButton_clicked();
    void changeConnection(bool result);
};

#endif // WIFIWINDOW_H
