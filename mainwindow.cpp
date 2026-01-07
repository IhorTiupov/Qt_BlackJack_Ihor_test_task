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
    connect(ui->pushButtonRestart, &QPushButton::clicked,
            this, &MainWindow::onRestartClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onHitClicked()
{
    game_m.playerHit();
    view_m->updateFromGame(game_m);

    if (game_m.gameState() == GameState::Finished)
    {
        ui->pushButtonRestart->setEnabled(true);
    }

}

void MainWindow::onStandClicked()
{
    game_m.playerStand();
    view_m->updateFromGame(game_m);

    if (game_m.gameState() == GameState::Finished)
    {
        ui->pushButtonRestart->setEnabled(true);
    }
}

void MainWindow::onRestartClicked()
{
    if(game_m.gameState() == GameState::Finished)
    {
        game_m.startNewGame();
        view_m->updateFromGame(game_m);
        ui->pushButtonRestart->setEnabled(false);
    }
}
