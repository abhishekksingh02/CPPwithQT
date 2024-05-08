#include <QCoreApplication>
#include <QDebug>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //qDebug() << "Hello Abhishek....";

    // Declaring the List
    QList<QString> stringList;

    //Put Data in the List
    stringList <<" My name " << " is " <<" Abhishek " <<" Singh ";
    // It would be like ["My name","is","Abhishek","Singh"]

    // We can also declare list as:
    stringList.append("Welcome");
    stringList.append("Abhishek...");

    //Getting the data from the list
    qDebug() << stringList[0];

    //Getting the number of elements
    qDebug() <<"The number of elements in String List is: " <<stringList.count();

    //Loop through the element in the list
    for(int i=0;i<stringList.count();i++){
        qDebug() <<"The element at index " << QString::number(i) << " is " << stringList.at(i);
    }

    return a.exec();
}
