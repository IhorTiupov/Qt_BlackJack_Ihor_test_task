#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QDebug>

//#include "logic/Player.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto* scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QPixmap pix(":/cards/assets/cards/PNG/card_back.png");

    if(pix.isNull())
    {
        qDebug() <<"Image is not founded!";
    }
    else
    {
        qDebug()<<"Image is loaded!";
        scene->addPixmap(pix);
        scene->setSceneRect(pix.rect());
    }
}



MainWindow::~MainWindow()
{
    delete ui;
}

