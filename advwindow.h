#ifndef ADVWINDOW_H
#define ADVWINDOW_H

#include <QMainWindow>
#include <QSettings>

namespace Ui {
class AdvWindow;
}

class AdvWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdvWindow(QWidget *parent = nullptr);
    ~AdvWindow();

    void loadSettings();

private:
    Ui::AdvWindow *ui;
    QSettings *settings;
    QSettings *default_settings;

signals:
    void settingWindow();

private slots:
    void on_backButton_clicked();
    void on_upPlusButton_clicked();
    void on_upMinusButton_clicked();
    void on_startVatMinusButton_clicked();
    void on_startVatPlusButton_clicked();
    void on_finishVatMinusButton_clicked();
    void on_finishVatPlusButton_clicked();
    void on_saveButton_clicked();
    void setSaveEnabled();
    void on_defaultButton_clicked();
    void on_speedVatSlider_sliderMoved(int value);
    void on_fullVatSlider_sliderMoved(int value);
    void on_speedDoorSlider_sliderMoved(int value);
    void changeConnection(bool result);
};

#endif // ADVWINDOW_H
