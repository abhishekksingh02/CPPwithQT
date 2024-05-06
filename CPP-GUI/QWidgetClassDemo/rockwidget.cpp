#include "rockwidget.h"
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>


RockWidget::RockWidget(QWidget *parent): QWidget{parent}
{
    //setWindowTitle("Rock Widget Here.");// Through this property we set the window title.

    // This will add label to the widget
    // QLabel * label = new QLabel(this);
    // label->setText("this is my label");

    // Adding a styled widget and moving it around
    QLabel * label1 = new QLabel(this);
    label1->setText("This is my coloured label");
    QPalette label1palette; // Helps to add colour
    label1palette.setColor(QPalette::Window,Qt::yellow);// Only Window will set colour in background
    label1palette.setColor(QPalette::WindowText,Qt::red);// WindowText will set colour in text
    QFont label1font("Times", 20, QFont::Bold);// This will Set the font and the size of the font
    label1->move(50,50);// This move() will move the lebl to 50 by right and 50 by down.
    label1->setFont(label1font);// calling the obj to the set the font
    label1->setPalette(label1palette);// calling the obj to the set the colour
    label1->setAutoFillBackground(true);// If we don't set this AutoFillBackground true, this will not work.

    // Adding label 2
    QLabel * myLabel2 = new QLabel(this);
    QFont myLabel2font("Times", 20, QFont::Bold);
    QPalette myLabel2palette;
    myLabel2palette.setColor(QPalette::Window,Qt::green);
    myLabel2palette.setColor(QPalette::WindowText,Qt::red);
    myLabel2->setText("This is my label 2");
    myLabel2->move(70,120);
    myLabel2->setAutoFillBackground(true);
    myLabel2->setFont(myLabel2font);
    myLabel2->setPalette(myLabel2palette);

    // Adding button and connect to slot
    QFont btnFont("Times", 30, QFont::Bold);
    QPushButton * btn = new QPushButton(this);
    btn->setText("Click Here");
    btn->setFont(btnFont);
    btn->move(100,200);
    connect(btn,SIGNAL(clicked()),this,SLOT(buttonClicked()));


}

void RockWidget::buttonClicked()
{
    QMessageBox::information(this,"Message","You Have Clicked On That Button.");
}

QSize RockWidget::sizeHint() const
{
    return QSize(500,500);
}
