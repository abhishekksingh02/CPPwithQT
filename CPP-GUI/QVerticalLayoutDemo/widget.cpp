#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    /*
    //Declaring the Vlayout
    QVBoxLayout * Vlayout = new QVBoxLayout();

    // Adding things to the layout

    Vlayout->addWidget(ui->oneButton);
    Vlayout->addWidget(ui->twoButton);
    Vlayout->addWidget(ui->threeButton);
    Vlayout->addWidget(ui->fourButton);
    Vlayout->addWidget(ui->fiveButton);

    // Setting the layout
    setLayout(Vlayout);
    */



}

Widget::~Widget()
{
    delete ui;
}
