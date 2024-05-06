#include "mainwindow.h"
#include <QDebug>
#include <QMenuBar>
#include <QPushButton>
#include <QStatusBar>
#include <QAction>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    QPushButton * button = new QPushButton("Hello");
    setCentralWidget(button); // setCentralWidhet will center the Whatever text mention in the widget

    // Declaring the Quit action
    QAction * quitAction = new QAction(this);
    quitAction->setText("Quit");

    connect(quitAction, &QAction::triggered,[=](){
        QApplication::quit();
    });

    //Adding menu to the widget
    QMenu * fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(quitAction);// This method will generate one message to quit and when clicked on it the window will get close

    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Windows");
    menuBar()->addMenu("Settings");
    menuBar()->addMenu("Help");

    //Add status bar message
    statusBar()->showMessage("Uploading File...",3000);

}

MainWindow::~MainWindow()
{

}

QSize MainWindow::sizeHint() const
{
    return QSize(500,500);
}
