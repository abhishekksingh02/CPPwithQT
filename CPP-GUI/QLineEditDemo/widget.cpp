#include "widget.h"
// #include "ui_widget.h"
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QLineEdit>

Widget::Widget(QWidget *parent): QWidget(parent){

    // First Name
    QLabel * FirstNamelabel = new QLabel("First Name", this);
    FirstNamelabel->setMinimumSize(70,50);
    FirstNamelabel->move(10,10);

    QLineEdit * FirstNameLineEdit = new QLineEdit(this);
    FirstNameLineEdit->setMinimumSize(200,50);
    FirstNameLineEdit->move(100,10);

    // Last Name
    QLabel * LastNamelabel = new QLabel("Last Name", this);
    LastNamelabel->setMinimumSize(70,50);
    LastNamelabel->move(10,70);

    QLineEdit * LastNameLineEdit = new QLineEdit(this);
    LastNameLineEdit->setMinimumSize(200,50);
    LastNameLineEdit->move(100,70);

    // City Name
    QLabel * CityNamelabel = new QLabel("City Name", this);
    CityNamelabel->setMinimumSize(70,50);
    CityNamelabel->move(10,130);

    QLineEdit * CityNameLineEdit = new QLineEdit(this);
    CityNameLineEdit->setMinimumSize(200,50);
    CityNameLineEdit->move(100,130);

    QFont buttonFont("Times" , 20, QFont::Bold);
    QPushButton * button = new QPushButton("Grab Data", this);
    button->setFont(buttonFont);
    button->move(80,190);

    connect(button,&QPushButton::clicked,[=](){ // connecting sot to the signal using labda expression

        QString firstName = FirstNameLineEdit->text();
        QString lastName  = LastNameLineEdit->text();
        QString city  = CityNameLineEdit->text();

        if(!firstName.isEmpty() && !lastName.isEmpty() && !city.isEmpty()){
        // Giving condition that if any field would be empty it will generate mmsg on the console regarding the same

            qDebug() <<"First Name is: " << firstName;
            qDebug() <<"Last  Name is: " << lastName;
            qDebug() <<"City Name is: " << city;
        }
        else{
            qDebug() <<"One of the fields is empty, kindly check!";
        }
    });

    // Respond to the signal using QLineEdits
    /* // CursorPositionChanged : It basically display the current line and the column number of the cursor position.
    connect(FirstNameLineEdit,&QLineEdit::cursorPositionChanged,[=]()
            {
        qDebug() << "The Current cursor position is: " << FirstNameLineEdit -> cursorPosition();
    });
    */

    /*// editingFinished: Emitted when the user clicks enter or when the line edit looses focus.
    connect(FirstNameLineEdit,&QLineEdit::editingFinished,[=] ()
            {
        qDebug() << "Editting Finished: ";
    });
    */

    /*// returnPressed
    connect(FirstNameLineEdit,&QLineEdit::returnPressed,[=] ()
            {
                qDebug() << "Return Pressed: ";
            });
    */

    /*//selectionChanged
    connect(FirstNameLineEdit,&QLineEdit::selectionChanged,[=] ()
            {
                qDebug() << "Selection Changed: ";
            });
    */

    //textChanged
    /*connect(FirstNameLineEdit,&QLineEdit::textChanged,[=] ()
            {
        qDebug() << "Text Changed To: " << FirstNameLineEdit->text();
            });
    */

    // textEditted
    connect(FirstNameLineEdit,&QLineEdit::textEdited,[=] ()
            {
                qDebug() << "Text Editted and Changed To: " << FirstNameLineEdit->text();
            });

    // Hint text : we can set the hint text so that user know what to type in that text area

    FirstNameLineEdit->setPlaceholderText("First Name");
    LastNameLineEdit->setPlaceholderText("Last Name");
    CityNameLineEdit->setPlaceholderText("City Name");
}
Widget::~Widget()
{

    }
