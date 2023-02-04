#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QMainWindow>

namespace Ui {
class AboutWindow;
}

class AboutWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AboutWindow(QWidget *parent = nullptr);
    ~AboutWindow();

private:
    Ui::AboutWindow *ui;

signals:
    void settingWindow();
private slots:
    void on_backButton_clicked();
    void changeConnection(bool result);
};

#endif // ABOUTWINDOW_H
