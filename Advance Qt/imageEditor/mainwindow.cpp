#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPainter>
#include <QBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->brightnessSlider, &QSlider::valueChanged,this,&MainWindow::on_brightnessSlider_valueChanged);
    connect(ui->contrastSlider, &QSlider::valueChanged,this,&MainWindow::on_contrastSlider_valueChanged);
    connect(ui->loadButton, &QPushButton::clicked, this,&MainWindow::on_loadButton_clicked);
    connect(ui->saveButton, &QPushButton::clicked,this,&MainWindow::on_saveButton_clicked);
    connect(ui->cropButton, &QPushButton::clicked,this,&MainWindow::on_cropButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp *.webp)"));
    if (!fileName.isEmpty())
    {
        originalImage = QImage(fileName);
        if (originalImage.isNull())
        {
            qDebug() << "Failed to load image from:" << fileName;
            return;
        }
        editedImage = originalImage;
        ui->imageLabel->setPixmap(QPixmap::fromImage(editedImage).scaled(ui->imageLabel->width(), ui->imageLabel->height(), Qt::KeepAspectRatio));
    }

}


void MainWindow::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image"),"", tr("Image Files (*.png *.jpg *.bmp *.webp)"));
    if (!fileName.isEmpty())
    {
        editedImage.save(fileName);
    }
}


void MainWindow::on_cropButton_clicked()
{
    if (!editedImage.isNull())
    {
        QRect cropRect = QRect(50, 50, editedImage.width() - 100, editedImage.height() - 100);
        editedImage = editedImage.copy(cropRect);
        ui->imageLabel->setPixmap(QPixmap::fromImage(editedImage).scaled(ui->imageLabel->width(), ui->imageLabel->height(), Qt::KeepAspectRatio));
    }
}


void MainWindow::on_brightnessSlider_valueChanged(int value)
{
    adjustImage();
}


void MainWindow::on_contrastSlider_valueChanged(int value)
{
    adjustImage();
}

void MainWindow::adjustImage()
{
    if(!originalImage.isNull())
    {
        int brightness = ui->brightnessSlider->value();
        int contrast = ui->contrastSlider->value();
        editedImage  = applyBrightnessContrast(originalImage, brightness, contrast);
        ui->imageLabel->setPixmap(QPixmap::fromImage(editedImage).scaled(ui->imageLabel->width(),ui->imageLabel->height(),Qt::IgnoreAspectRatio));
    }
}

QImage MainWindow::applyBrightnessContrast(const QImage &image, int brightness, int contrast)
{   QImage result = image;
    int width = result.width();
    int height = result.height();

    for(int y=0;y<height;++y)
    {
        for(int x=0;x<width;++x)
        {
            QColor color = QColor(result.pixel(x,y));
            int r = color.red();
            int g = color.green();
            int b = color.blue();

            //Applying brightness
            r=qBound(0, r+brightness,255);
            g=qBound(0, g+brightness,255);
            b=qBound(0, b+brightness,255);

            //Applying contrast
            r = qBound(0,((r-128)*contrast/100)+128,255);
            g = qBound(0,((g-128)*contrast/100)+128,255);
            b = qBound(0,((b-128)*contrast/100)+128,255);

            result.setPixel(x,y,qRgb(r,g,b));

        }
    }
    return result;
}



void MainWindow::on_exitButton_clicked()
{
    close();
}

