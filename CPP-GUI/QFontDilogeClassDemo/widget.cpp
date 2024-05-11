#include "widget.h"
#include "ui_widget.h"
#include <QFontDialog>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_chooseFontBUtton_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(
        &ok, QFont("Helvetica [Cronyx]", 10), this);
    if (ok) {

        ui->label->setFont(font);

    } else {

        QMessageBox::information(this,"Message","User didn't choose any Font..");
    }

}

