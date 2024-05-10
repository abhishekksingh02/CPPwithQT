#include "infodialogue.h"
#include "ui_infodialogue.h"

InfoDialogue::InfoDialogue(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InfoDialogue)
{
    ui->setupUi(this);
}

InfoDialogue::~InfoDialogue()
{
    delete ui;
}

void InfoDialogue::on_buttonBox_clicked(QAbstractButton *button)
{
    QDialogButtonBox::StandardButton stdButton = ui->buttonBox->standardButton(button);

    if( stdButton == QDialogButtonBox::Ok){
        accept();
        qDebug() <<"Ok button clicked.";
    }

    if( stdButton == QDialogButtonBox::Save){
        qDebug() <<"Save button clicked.";
    }

    if( stdButton == QDialogButtonBox::Open){
        qDebug() <<"Open button clicked.";
    }

    if( stdButton == QDialogButtonBox::Cancel){

        reject();
        qDebug() <<"Cancel button clicked.";
    }

    if( stdButton == QDialogButtonBox::No){
        qDebug() <<"No button clicked.";
    }

    if( stdButton == QDialogButtonBox::NoToAll){
        qDebug() <<"No to all button clicked.";
    }


}

