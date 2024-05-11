#include "customdialog.h"
#include "ui_customdialog.h"

customDialog::customDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::customDialog)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("QPushButton{background-color: green; color: white;}");

    //ui->pushButton->setStyleSheet("QPushButton{background-color: red; color: white;}");
}

customDialog::~customDialog()
{
    delete ui;
}
