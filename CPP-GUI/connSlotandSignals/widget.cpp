#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
// PROGRAM TO ESTABLISH THE CONNECTION BETWEEN SIGNALS AND SLOTS
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 1. String notation
    //connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(changeText()));// way to establish connection using String notation

    // 2. Establishing connection using Functor Notation
    //connect(ui->pushButton, &QPushButton :: clicked, this, &Widget::changeText);

    // 3. Establishing connection using Functor Notation Lambda
    connect(ui->pushButton, &QPushButton :: clicked,[=](){
        ui->label->setText("Lambda Function is responding");
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeText()
{
    qDebug() <<"User clicked On Button" ;
    ui->label->setText("Hello There, You have just clicked on the button..");
}
