#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //This will let us select multiple item simultaneously
    ui->listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::on_addItemButton_clicked()
{
    ui->listWidget->addItem("My Item");
}


void Widget::on_deleteItemButton_clicked()
{
    // Delete the item by using method named takeItem

    ui->listWidget->takeItem(ui->listWidget->currentRow());

}


void Widget::on_selectedItemButton_clicked()
{
    // Get the list of the selected items and also it will return the current index
    QList<QListWidgetItem * > list = ui->listWidget->selectedItems();

    for(int i=0;i<list.count();i++){

        qDebug() << "Selected Items are: " << list.at(i)->text() << " , row number id: " <<
            ui->listWidget->row(list.at(i));
    }
}

