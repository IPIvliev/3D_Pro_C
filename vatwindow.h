#ifndef VATWINDOW_H
#define VATWINDOW_H

#include <QMainWindow>

namespace Ui {
class VatWindow;
}

class VatWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit VatWindow(QWidget *parent = nullptr);
    ~VatWindow();

private slots:
    void on_backButton_clicked();

    void on_inButton_pressed();

    void on_inButton_released();

    void on_outButton_pressed();

    void on_outButton_released();

    void changeConnection(bool result);

signals:
    void serviceWindow();

private:
    Ui::VatWindow *ui;
};

#endif // VATWINDOW_H
