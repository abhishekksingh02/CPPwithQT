#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(const QHostAddress &address : QNetworkInterface::allAddresses())
    {
        if(address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
        {
            qDebug() <<"IP Address is: " <<address.toString();
        }
    }
    qDebug() << "--------------------------------------------------";
    for(const QNetworkInterface &eth : QNetworkInterface::allInterfaces())
    {
        qDebug() << eth.name();
        qDebug() << eth.humanReadableName();
        qDebug() << eth.hardwareAddress();
        qDebug() << eth.type();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
