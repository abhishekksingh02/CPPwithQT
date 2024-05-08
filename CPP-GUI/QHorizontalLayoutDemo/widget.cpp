#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    /*
    //Defining the layout
    QHBoxLayout * layout = new QHBoxLayout();

    //Adding things to the layout
    layout->addWidget(ui->oneButton);
    layout->addWidget(ui->twoButton);
    layout->addWidget(ui->threeButton);
    layout->addWidget(ui->fourButton);
    layout->addWidget(ui->fiveButton);

    //Setting the layout to widget
    setLayout(layout);
    */
}

Widget::~Widget()
{
    delete ui;
}
