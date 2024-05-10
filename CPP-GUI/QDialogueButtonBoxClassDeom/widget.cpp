#include "widget.h"
#include "ui_widget.h"
#include "infodialogue.h"

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

void Widget::on_showInfoButton_clicked()
{
    InfoDialogue * dilogue = new InfoDialogue(this);

    connect(dilogue, &InfoDialogue::accepted,[=] () {

        qDebug() <<"Dialogue Accepted..";
    });

    connect(dilogue, &InfoDialogue::rejected,[=] () {

        qDebug() <<"Dialogue Rejected...";
    });

    dilogue->exec();
}

