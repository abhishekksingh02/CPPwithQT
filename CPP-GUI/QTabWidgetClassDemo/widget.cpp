#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Adding a new tab programatically
    // Decalaring the QWidget
    QWidget * widget = new QWidget(this);

    //Declaring the layout for the widget
    QVBoxLayout * layout = new QVBoxLayout(this);
    layout->addWidget(new QPushButton("Button 1" , this));
    layout->addWidget(new QPushButton("Button 2" , this));
    layout->addWidget(new QPushButton("Button 3" , this));
    QPushButton * button4 = new QPushButton("Button 4",this);
    connect(button4,&QPushButton::clicked,[=](){
        qDebug() <<"Button 4 from custom tab clicked";
    });
    layout->addWidget(button4);
    //Declaring vertical spacer
    layout->addSpacerItem(new QSpacerItem(100,200));

    //Set the layout to the widget
    widget->setLayout(layout);

    //Adding the widget to the layout
    ui->tabWidget->addTab(widget,"Tab 4");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_tab1Button_clicked()
{
    qDebug() <<"Tab 1 Button clicked..";
}

