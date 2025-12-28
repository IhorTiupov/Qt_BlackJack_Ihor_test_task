#pragma once

#include <QGraphicsView>


class BlackJackGame;
class CardItem;


class GameView: public QGraphicsView
{
    Q_OBJECT;
public:
    explicit GameView(QWidget* parent = nullptr);

    void updateFromGame(const BlackJackGame& game);

private:
    void clearScene();
    void drawPlayerHand(const BlackJackGame& game);
    void drawDealerHand(const BlackJackGame& game);
    void drawDeck();

private:
    QGraphicsScene* scene_m;
};
