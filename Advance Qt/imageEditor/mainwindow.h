#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loadButton_clicked();
    void on_saveButton_clicked();
    void on_cropButton_clicked();
    void on_brightnessSlider_valueChanged(int value);
    void on_contrastSlider_valueChanged(int value);
    void on_exitButton_clicked();

public:
    Ui::MainWindow *ui;
    QImage originalImage;
    QImage editedImage;
    QLabel *imageLabel;
    QSlider *brightnessSlider;
    QSlider *contrastSlider;
    QPushButton *loadButton;
    QPushButton *saveButton;
    QPushButton *cropButton;

    void adjustImage();
    QImage applyBrightnessContrast(const QImage &image, int brightness, int contrast);
};
#endif // MAINWINDOW_H
