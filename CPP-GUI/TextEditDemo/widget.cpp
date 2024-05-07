#include "widget.h"
// #include "ui_widget.h"
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QDebug>

Widget::Widget(QWidget *parent): QWidget(parent)
{
    QFont labelFont("Times", 20, QFont::Bold);
    QLabel * mLabel = new QLabel("This is my text", this);
    mLabel->setFont(labelFont);
    mLabel->move(100,25);

    QTextEdit * textEdit = new QTextEdit(this);
    textEdit->move(70,55);

    // textChanged
    /*connect(textEdit, &QTextEdit::textChanged,[=](){
        qDebug() <<"Text Changed";
    });
    */

    /*
       1) Copy
       2) Paste
       3) Undo
       4) redu
       5) setHtml
       6) setPlinText
    */

    // Copy button
    QPushButton * copyButton = new QPushButton("Copy",this);
    copyButton->setMinimumSize(50,25);
    copyButton->move(10,250);
    connect(copyButton,&QPushButton::clicked,[=](){// Connecting Slots and Signal With Lambda Function
        textEdit->copy();
    });

    // Cut button
    QPushButton * cutButton = new QPushButton("Cut",this);
    cutButton->setMinimumSize(50,25);
    cutButton->move(110,250);
    connect(cutButton,&QPushButton::clicked,[=](){
        textEdit->cut();
    });

    // Paste button
    QPushButton * pasteButton = new QPushButton("Paste",this);
    pasteButton->setMinimumSize(50,25);
    pasteButton->move(210,250);
    connect(pasteButton,&QPushButton::clicked,[=](){
        textEdit->paste();
    });

    //Undo button
    QPushButton * undoButton = new QPushButton("Undo" , this);
    undoButton->setMinimumSize(50,25);
    undoButton->move(310,250);
    connect(undoButton,&QPushButton::clicked,[=](){
        textEdit->undo();
    });

    // Redo button
    QPushButton * reduButton = new QPushButton("Redu" , this);
    reduButton->setMinimumSize(50,25);
    reduButton->move(410,250);
    connect(reduButton,&QPushButton::clicked,[=](){
        textEdit->redo();
    });

    //Set text and HTML to the text edit
    QPushButton * plainTextButton = new QPushButton("Plain Text", this);
    plainTextButton->setMinimumSize(100,25);
    plainTextButton->move(10,310);
    connect(plainTextButton,&QPushButton::clicked,[=](){
        textEdit->setPlainText("My Name is Abhishek Singh and i am putting this text statically");
    });
    //This will convert the HTML text to normal output
    QPushButton * htmlTextButton = new QPushButton("HTML", this);
    htmlTextButton->setMinimumSize(100,25);
    htmlTextButton->move(120,310);
    connect(htmlTextButton,&QPushButton::clicked,[=](){
        textEdit->setHtml("<h1>My First Heading</h1><p>My first paragraph.</p>");
    });

    setFixedSize(400,400);
}
Widget::~Widget()
{

}
