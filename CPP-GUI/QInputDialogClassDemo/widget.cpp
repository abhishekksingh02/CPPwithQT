#include "widget.h"
#include "ui_widget.h"
#include <QInputDialog>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{

    bool ok;
    double d = QInputDialog::getDouble(this, tr("QInputDialog::getDouble()"),
                                       tr("Amount:"), 37.56, -10000, 10000, 2, &ok,
                                       Qt::WindowFlags(), 1);
    if(ok){

        qDebug() <<"Your double value is: " << QString::number(d);
    }


}

