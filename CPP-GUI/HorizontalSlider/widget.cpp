#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // String Notation
    //connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));

    // Functor Notation
    //connect(ui->horizontalSlider,&QSlider::valueChanged, ui->progressBar,&QProgressBar::setValue);

    // Functor Notation using Lambda Function
    connect(ui->horizontalSlider, &QSlider::valueChanged, [=]() {
        ui->progressBar->setValue(ui->horizontalSlider->value());
    });
}

Widget::~Widget()
{
    delete ui;
}
