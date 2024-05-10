#include "widget.h"
#include "ui_widget.h"
#include "infodialogue.h"
#include <QDebug>

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

void Widget::on_provideInfoButton_clicked()
{
    InfoDialogue * dialogue = new InfoDialogue(this);
    /*
    //Showing the model
    int ret = dialogue->exec();

    if( ret==QDialog::Accepted){

        QString position = dialogue->getPosition();
        QString os = dialogue->getFavouriteOs();
        qDebug() << "Dialogue Accepted, position is: " << position;
        qDebug() << "Favourite OS is: " << os;

        ui->infoLabel->setText("Your position is: " + position + " and your favourite OS is: " + os );

    }

    if( ret==QDialog::Rejected){
        qDebug() << "Dialogue Rejected..";
    }
    */

    //Show the dialogue non model
    connect(dialogue,&InfoDialogue::accepted,[=](){

        QString position = dialogue->getPosition();
        QString os = dialogue->getFavouriteOs();
        qDebug() << "Dialogue Accepted, position is: " << position;
        qDebug() << "Favourite OS is: " << os;

        ui->infoLabel->setText("Your position is: " + position + " and your favourite OS is: " + os );

    });


    connect(dialogue,&InfoDialogue::rejected,[=](){

        qDebug() << "Dialogue Rejected..";

    });

    dialogue->show();
    dialogue->raise();
    dialogue->activateWindow();
}

