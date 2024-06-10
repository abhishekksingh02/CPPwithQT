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
    //Establishing connection to the database
    DB_Connection = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connection.setDatabaseName("/home/abhishek/Documents/DB/Test");//Database path
    if(DB_Connection.open())
    {
        qDebug() << "Databse Connection Successfull";
    }
    else
    {
        qDebug() << "Databse Connection Failure..";
        qDebug() << "Error: " << DB_Connection.lastError();
    }
}

void MainWindow::on_pushButton_Insert_Data_clicked()
{
    //Logic for the insertion of the data
    this->getConnection();
    DB_Connection.open();
    // QSqlDatabase::database().transaction();
    QSqlQuery QueryInsertData(DB_Connection);
    QueryInsertData.prepare("INSERT INTO test1(Name,Age,Email) VALUES(:Name,:Age,:Email);");
    // QueryInsertData.bindValue(":id",ui->lineEdit->text());
    QueryInsertData.bindValue(":Name",ui->lineEdit_2->text());
    QueryInsertData.bindValue(":Age",ui->lineEdit_3->text());
    QueryInsertData.bindValue(":Email",ui->lineEdit_4->text());
    if(!QueryInsertData.exec())
    {
        qDebug() <<"Error." << QueryInsertData.lastError();
    }
    QSqlDatabase::database().commit();
    DB_Connection.close();
    on_pushButton_View_Data_clicked();

}


void MainWindow::on_pushButton_Update_Data_clicked()
{
    //Logic for update of data
    this->getConnection();
    DB_Connection.open();
    QSqlQuery QueryUpdateData(DB_Connection);
    QueryUpdateData.prepare("UPDATE test1 SET Name=:Name,Age=:Age,Email=:Email WHERE id=:id");
    QueryUpdateData.bindValue(":id",ui->lineEdit->text());
    QueryUpdateData.bindValue(":Name",ui->lineEdit_2->text());
    QueryUpdateData.bindValue(":Age",ui->lineEdit_3->text());
    QueryUpdateData.bindValue(":Email",ui->lineEdit_4->text());
    // QueryUpdateData.bindValue(":id",ui->lineEdit->text());
    if(!QueryUpdateData.exec())
    {
        qDebug() <<"Error." << QueryUpdateData.lastError();
    }
    QSqlDatabase::database().commit();
    DB_Connection.close();
}


void MainWindow::on_pushButton_Delete_Data_clicked()
{
    //Logic for deleting the data fromm DB
    this->getConnection();
    // DB_Connection.open();
    QSqlQuery QueryDeleteData(DB_Connection);
    QueryDeleteData.prepare("DELETE FROM test1 WHERE id=:id");
    QueryDeleteData.bindValue(":id",ui->lineEdit->text());
    if(!QueryDeleteData.exec())
    {
        qDebug() <<"Error." << QueryDeleteData.lastError();
    }
    // QSqlDatabase::database().commit();
    // DB_Connection.close();
    on_pushButton_View_Data_clicked();


}


void MainWindow::on_pushButton_View_Data_clicked()
{
    //Logic for Displaying the data
    this->getConnection();
    QSqlQuery *qry =new QSqlQuery();
    QSqlQueryModel *model =new QSqlQueryModel();

    qry->prepare("SELECT * FROM test1;");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);

    // DB_Connection.open();
    // QSqlQuery QueryViewData(DB_Connection);
    // QueryViewData.prepare("SELECT * FROM test1");
    // int numOfRowsToDisplay = 10;
    // if(QueryViewData.exec())
    // {
    //     // qDebug() <<"Error." << QueryViewData.lastError();
    //     ui->tableView->setRowCount(numOfRowsToDisplay);
    //     int RowNumber = 0;
    //     while(QueryViewData.next())
    //     {
    //         ui->tableView->setItem(RowNumber, 0, new QtableViewItem(QString(QueryViewData.value("id").toString())));
    //         ui->tableView->setItem(RowNumber, 1, new QtableViewItem(QString(QueryViewData.value("Name").toString())));
    //         ui->tableView->setItem(RowNumber, 2, new QtableViewItem(QString(QueryViewData.value("Age").toString())));
    //         ui->tableView->setItem(RowNumber, 3, new QtableViewItem(QString(QueryViewData.value("Email").toString())));
    //         RowNumber+=1;
    //     }
    // }
    // QSqlDatabase::database().commit();
    // DB_Connection.close();
}


void MainWindow::on_pushButton_clicked()
{
    close();
}

