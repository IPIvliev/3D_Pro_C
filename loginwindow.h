#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QSettings>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

    void loadSettings();

private:
    Ui::LoginWindow *ui;
    QSettings *settings;

signals:
    void settingWindow();

private slots:
    void on_backButton_clicked();
    void changeConnection(bool result);
};

#endif // LOGINWINDOW_H
