#include "widget.h"
#include "ui_widget.h"
#include <stdlib.h>
#include <time.h>
#include <qdebug.h>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //Initialize
    srand(time(NULL));

    //Generate (1-10)
    secretNumber = rand() % 10 + 1;
    qDebug() <<"Secret Number generated: " << QString::number(secretNumber);

     ui->startOverButton->setDisabled(true);

     ui->messageLabel->setText("");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_guessButton_clicked()
{
    guessNumber = ui->spinBox->value();
    qDebug() <<"The Guessed Number is: " << QString :: number(guessNumber);

    if(guessNumber == secretNumber)
    {
        // We will displlay Congratutions message

        ui->messageLabel->setText("Congratulations!! The number is: " + QString::number(secretNumber));

        // Disable the guess button once number guessed it right

        ui->guessButton->setDisabled(true);
        ui->startOverButton->setDisabled(false);

    }
    else
    {
        if(secretNumber < guessNumber)
        {
            // We will Say Number is Lower than that

            ui->messageLabel->setText("Number is Lower than that");
        }
        if(secretNumber > guessNumber)
        {
            // We will Say Number is Greater than that

            ui->messageLabel->setText("Number is Greater than that");
        }
    }
}


void Widget::on_startOverButton_clicked()

{   //Enable guess button
    ui->guessButton->setDisabled(false);

    //Disable the reset button
    ui->startOverButton->setDisabled(true);


    // put the spinbox to 1
    ui->spinBox->setValue(1);

    //Regenerate the Random number
    secretNumber = rand() % 10 + 1;

    qDebug() << "New Random Number is: " << secretNumber;
    //Clear the message label
    ui->messageLabel->setText("");

}

