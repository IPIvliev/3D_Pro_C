#include "dialog_default_window.h"
#include "ui_dialog_default_window.h"

DefaultDialog::DefaultDialog( QWidget* parent ) :
    QDialog(parent),
    ui(new Ui::DefaultDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowTitleHint);
}

DefaultDialog::~DefaultDialog()
{
    delete ui;
}

void DefaultDialog::on_yesButton_clicked()
{
    accept();
}


void DefaultDialog::on_noButton_clicked()
{
    reject();
}

