#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_windowsCheckbox_toggled(bool checked);

    void on_coffeeCheckbox_toggled(bool checked);

    void on_maleRadiobutton_toggled(bool checked);

    void on_grabData_clicked();

    void on_setStateButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
