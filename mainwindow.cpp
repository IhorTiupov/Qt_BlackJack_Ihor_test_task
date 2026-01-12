#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "soundmanager.h"

#include <QPushButton>


SoundManager *soundManager;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    soundManager = new SoundManager(this);

    soundManager->startBackgroundMusic();
    soundManager->playCardDeal();

    view_m = ui->graphicsView;

    game_m.startNewGame();
    view_m->updateFromGame(game_m);

    connect(ui->pushButtonHit, &QPushButton::clicked,
            this, &MainWindow::onHitClicked);
    connect(ui->pushButtonStand, &QPushButton::clicked,
            this, &MainWindow::onStandClicked);
    connect(ui->pushButtonRestart, &QPushButton::clicked,
            this, &MainWindow::onRestartClicked);

    connect(ui->pushButtonHit, &QPushButton::clicked,
            soundManager, &SoundManager::playButtonClick);

    connect(ui->pushButtonStand, &QPushButton::clicked,
            soundManager, &SoundManager::playButtonClick);

    connect(ui->pushButtonRestart, &QPushButton::clicked,
            soundManager, &SoundManager::playButtonClick);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (soundManager)
    {
        soundManager->stopBackgroundMusic();
    }
}

void MainWindow::onHitClicked()
{
    soundManager->playCardDeal();
    game_m.playerHit();
    view_m->updateFromGame(game_m);

    if (game_m.gameState() == GameState::Finished)
    {
        ui->pushButtonRestart->setEnabled(true);
    }
}

void MainWindow::onStandClicked()
{
    soundManager->playCardDeal();
    game_m.playerStand();
    view_m->updateFromGame(game_m);

    if (game_m.gameState() == GameState::Finished)
    {
        ui->pushButtonRestart->setEnabled(true);
    }
}

void MainWindow::onRestartClicked()
{
    soundManager->playCardDeal();
    if(game_m.gameState() == GameState::Finished)
    {
        game_m.startNewGame();
        view_m->updateFromGame(game_m);
        ui->pushButtonRestart->setEnabled(false);
    }
}
