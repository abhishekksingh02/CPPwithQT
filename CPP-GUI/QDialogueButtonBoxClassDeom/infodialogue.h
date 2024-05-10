#ifndef INFODIALOGUE_H
#define INFODIALOGUE_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class InfoDialogue;
}

class InfoDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialogue(QWidget *parent = nullptr);
    ~InfoDialogue();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::InfoDialogue *ui;
};

#endif // INFODIALOGUE_H
