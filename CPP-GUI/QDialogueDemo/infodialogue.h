#ifndef INFODIALOGUE_H
#define INFODIALOGUE_H

#include <QDialog>

namespace Ui {
class InfoDialogue;
}

class InfoDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialogue(QWidget *parent = nullptr);
    ~InfoDialogue();

    QString getFavouriteOs() const;

    QString getPosition() const;

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:

    QString position;
    QString favouriteOs;
    Ui::InfoDialogue *ui;
};

#endif // INFODIALOGUE_H
