#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::on_sendButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sendButton_clicked()
{
    QString message = ui->messageLineEdit->text();
    if(!message.isEmpty())
    {
        ui->chatTextEdit->append("ME: " + message);

        if(message.toLower() == "hi")
        {
            showMenuOptions();
        }
        else
        {
            performAction(message);
        }

        ui->messageLineEdit->clear();
    }
}

void MainWindow::showMenuOptions()
{
    ui->chatTextEdit->append("yourChatBot: Choose an option below:");
    ui->chatTextEdit->append("1. Show Current Time");
    ui->chatTextEdit->append("2. Open File Explorer");
    ui->chatTextEdit->append("3. Open Web(google.com)");
    ui->chatTextEdit->append("Type number to choose an action");
}

void MainWindow::performAction(const QString &action)
{
    if(action == "1")
    {
        QString currentTime = QDateTime::currentDateTime().toString();
        ui->chatTextEdit->append("yourChatBot: Current time is: " + currentTime);
    }
    else if(action == "2")
    {
        QString directory = QFileDialog::getExistingDirectory(this, "Open Directory","");
        if(!directory.isEmpty())
        {
            ui->chatTextEdit->append("yourChatBot: File Explorer opened at " + directory);
        }
    }
    else if(action == "3")
    {
        QDesktopServices::openUrl(QUrl("http://www.google.com"));
        ui->chatTextEdit->append("yourChatBot: Opening web browser at http://www.google.com");
    }
    else
    {
        ui->chatTextEdit->append("yourChatBot: Invalid option typed. Type 'hi' to see the menu options again.");
    }
}


void MainWindow::on_pushButton_clicked()
{
    close();
}

