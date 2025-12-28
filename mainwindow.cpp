#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    view_m = ui->graphicsView;

    game_m.startNewGame();
    view_m->updateFromGame(game_m);

    connect(ui->pushButtonHit, &QPushButton::clicked,
            this, &MainWindow::onHitClicked);

    connect(ui->pushButtonStand, &QPushButton::clicked,
            this, &MainWindow::onStandClicked);




    /*auto* scene = new QGraphicsScene(this);
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
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onHitClicked()
{
    game_m.playerHit();
    view_m->updateFromGame(game_m);
}

void MainWindow::onStandClicked()
{
    game_m.playerStand();
    view_m->updateFromGame(game_m);
}

