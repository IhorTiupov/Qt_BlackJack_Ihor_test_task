#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "logic/blackjackgame.h"
#include "ui/gameview.h"
#include <QMainWindow>

//class GameView;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onHitClicked();
    void onStandClicked();


private:
    GameView* view_m;
    BlackJackGame game_m;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
