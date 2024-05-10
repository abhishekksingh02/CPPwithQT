#include "infodialogue.h"
#include "ui_infodialogue.h"

InfoDialogue::InfoDialogue(QWidget *parent): QDialog(parent), ui(new Ui::InfoDialogue)
{
    ui->setupUi(this);
}

InfoDialogue::~InfoDialogue()
{
    delete ui;
}

void InfoDialogue::on_okButton_clicked()
{
    //Collecting information when user clicks on OK button
    QString userPosition = ui->positionLineEdit->text();

    if(!userPosition.isEmpty()){

        position = userPosition;

        if(ui->windowsRadioButton->isChecked()){
            favouriteOs = "Windows";
          }

        if(ui->macRadioButton->isChecked()){
            favouriteOs = "Mac";
         }
        if(ui->linuxRadioButton->isChecked()){
            favouriteOs = "Linux";
          }
        }

        //Accept the dialogue
        accept();
}


void InfoDialogue::on_cancelButton_clicked()
{
      //
    reject();
}

QString InfoDialogue::getPosition() const
{
    return position;
}

QString InfoDialogue::getFavouriteOs() const
{
    return favouriteOs;
}

