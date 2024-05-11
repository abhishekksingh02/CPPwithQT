#include "widget.h"
#include "ui_widget.h"
#include <QColorDialog>
#include <QFontDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setAutoFillBackground(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_textColourButton_clicked()
{
    QPalette palette = ui->label->palette();

    QColor color = palette.color(QPalette::WindowText);

    QColor chosenColor = QColorDialog::getColor(color,this,"Choose Text Color.");

    if(chosenColor.isValid()){

        palette.setColor(QPalette::WindowText,chosenColor);
        ui->label->setPalette(palette);
        qDebug() <<"User chose a valid color...";
    }
    else{
        qDebug() <<"User chose invalid color...";
    }
}


void Widget::on_backgroundBUtton_clicked()
{

    QPalette palette = ui->label->palette();

    QColor color = palette.color(QPalette::Window);

    QColor chosenColor = QColorDialog::getColor(color,this,"Choose Background Color.");

    if(chosenColor.isValid()){

        palette.setColor(QPalette::Window,chosenColor);
        ui->label->setPalette(palette);
        qDebug() <<"User chose a valid color...";
    }
    else{
        qDebug() <<"User chose invalid color...";
    }
}


void Widget::on_fontButton_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(
        &ok, QFont("Helvetica [Cronyx]", 10), this);
    if (ok) {

        ui->label->setFont(font);

    } else {

    }

}

