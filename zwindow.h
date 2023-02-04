#ifndef ZWINDOW_H
#define ZWINDOW_H

#include <QMainWindow>

namespace Ui {
class ZWindow;
}

class ZWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ZWindow(QWidget *parent = nullptr);
    ~ZWindow();

private slots:
    void on_backButton_clicked();

    void on_aButton_clicked();

    void on_bButton_clicked();

    void on_cButton_clicked();

    void on_dButton_clicked();

    void on_stepButton_clicked();

    void on_stopButton_clicked();

    void on_upButton_pressed();

    void on_upButton_released();

    void on_zstopButton_pressed();

    void on_zstopButton_released();

    void on_downButton_pressed();

    void on_downButton_released();

    void changeConnection(bool result);

signals:
    void serviceWindow();

private:
    Ui::ZWindow *ui;
};

#endif // ZWINDOW_H
