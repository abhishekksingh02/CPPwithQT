#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Adding planets name to the comboBox
    ui->comboBox->addItem("Mercury");
    ui->comboBox->addItem("Earth");
    ui->comboBox->addItem("Mars");
    ui->comboBox->addItem("Venus");
    ui->comboBox->addItem("Jupiter");
    ui->comboBox->addItem("Saturn");
    ui->comboBox->addItem("Neptune");

    // Making the comboBox editable so that the  user would be able to add itmes during the run time
    ui->comboBox->setEditable(true);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_captureValueButton_clicked()
{
    qDebug() << "The currently selected Planet is: " << ui->comboBox->currentText()
             << "and the index is: " << QString::number(ui->comboBox->currentIndex());
}


void Widget::on_setValueButton_clicked()
{
    ui->comboBox->setCurrentIndex(5);
}


void Widget::on_getValueButton_clicked()
{
    qDebug() << "The combo Box currently has " << QString::number(ui->comboBox->count()) << " options into it and they are: ";

    for(int i=0;i<ui->comboBox->count();i++){
        qDebug() << "Index " <<QString::number(i) << ":" << ui->comboBox->itemText(i);
    }
}

