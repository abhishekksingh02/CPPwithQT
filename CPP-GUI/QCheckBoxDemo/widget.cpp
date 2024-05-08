#include "widget.h"
#include "ui_widget.h"
#include <QButtonGroup>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Instantiating ButtonGroup class object
    QButtonGroup * buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(ui->windowsCheckbox);
    buttonGroup->addButton(ui->linuxCheckbox);
    buttonGroup->addButton(ui->macCheckbox);

    //Making options as exclusive
    buttonGroup->setExclusive(true);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_windowsCheckbox_toggled(bool checked)
{
    if(checked){
        qDebug() <<"Windows Check Box is checked";
    }
    else{
        qDebug() <<"Windows Check Box is Unchecked.";
    }
}


void Widget::on_coffeeCheckbox_toggled(bool checked)
{
    if(checked){
        qDebug() <<"Coffee Check Box checked..";
    }
    else
    {
        qDebug() <<"Coffee Check Box is Unchecked...";
    }
}


void Widget::on_maleRadiobutton_toggled(bool checked)
{
    if(checked){
        qDebug() <<"Male Radio button checked...";
    }
    else
    {
        qDebug() <<"Male Radio button unchecked...";
    }
}


void Widget::on_grabData_clicked()
{
    if(ui->windowsCheckbox->isChecked()){
        qDebug() <<"Windows Check Box is checked...";
    }
    else{
        qDebug() <<"Windows Check Box is Unchecked...";
    }
}


void Widget::on_setStateButton_clicked()
{
    // For Exclusive Check Box
    if(ui->windowsCheckbox->isChecked()){
        ui->windowsCheckbox->setChecked(false);
    }
    else{
        ui->windowsCheckbox->setChecked(true);
    }

    // For non-exclusive Check Box
    if(ui->coffeeCheckbox->isChecked()){
        ui->windowsCheckbox->setChecked(false);
    }
    else{
        ui->windowsCheckbox->setChecked(true);
    }

    // For Radio Button Check box
    if(ui->maleRadiobutton->isChecked()){
        ui->windowsCheckbox->setChecked(false);
    }
    else{
        ui->windowsCheckbox->setChecked(true);
    }
}

