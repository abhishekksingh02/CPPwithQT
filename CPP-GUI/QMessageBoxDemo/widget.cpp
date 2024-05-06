#include "widget.h"
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent): QWidget(parent)
{
    QPushButton * button = new QPushButton(this);
    button->setText("Clicke Me");
    button->move(200,200);
    connect(button,&QPushButton::clicked,[=](){

        // Complex Approach
        /*QMessageBox message;
        message.setMinimumSize(300,200);
        message.setWindowTitle("Urgent!");
        message.setText("Something Happended..");
        message.setInformativeText("Do you want to close?");
        message.setIcon(QMessageBox::Critical);
        message.setStandardButtons(QMessageBox::Ok |  QMessageBox::Cancel);
        message.setDefaultButton(QMessageBox::Cancel);

        int resp  = message.exec();
        */

        //Critical Message
        /*int resp = QMessageBox::critical(this,"Urgent!!","An Error Occured. Do you want to close or Wait?",
                                         QMessageBox::Yes |  QMessageBox::Cancel);

        */

        // Information Message
        /*int resp = QMessageBox::information(this,"Urgent!!","An Error Occured. Do you want to close or Wait?",
                                         QMessageBox::Yes |  QMessageBox::Cancel);

        */

        // Question Message
        /*int resp = QMessageBox::question(this,"Urgent!!","An Error Occured. Do you want to close or Wait?",
                                            QMessageBox::Yes |  QMessageBox::Cancel);
        */

        int resp = QMessageBox::warning(this,"Urgent!!","An Error Occured. Do you want to close or Wait?",
                                         QMessageBox::Yes |  QMessageBox::Cancel);

        if(resp==QMessageBox::Yes)
        {
            qDebug() << "User clicked on Yes button.";
        }
        if(resp==QMessageBox::Cancel)
            {
            qDebug() << "User clicked on Cancel.";
        }
    });
}

Widget::~Widget()
{

}
