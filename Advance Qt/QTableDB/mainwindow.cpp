#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getConnection()
{
    //Establishing Connection to the database
    DB_Connection = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connection.setDatabaseName("/home/abhishek/Documents/DB/Test");//Database path
    if(DB_Connection.open())
    {
        qDebug() << "Databse Connection successfull";
    }
    else
    {
        qDebug() << "Databse Connection Failure..";
        qDebug() << "Error: " << DB_Connection.lastError();
    }

}
void MainWindow::on_pushButton_Insert_Data_clicked()
{
    this->getConnection();

    QSqlQuery QueryInsertData(DB_Connection);
    QueryInsertData.prepare("INSERT INTO test1(Name,Age,Email) VALUES(:Name,:Age,:Email);");
    QueryInsertData.bindValue(":id",ui->lineEdit->text());
    QueryInsertData.bindValue(":Name",ui->lineEdit_2->text());
    QueryInsertData.bindValue(":Age",ui->lineEdit_3->text());
    QueryInsertData.bindValue(":Email",ui->lineEdit_4->text());
    if(!QueryInsertData.exec())
    {
        qDebug() <<"Error." << QueryInsertData.lastError();
    }
    //QueryInsertData.exec();
    QSqlDatabase::database().commit();
    DB_Connection.close();
}

