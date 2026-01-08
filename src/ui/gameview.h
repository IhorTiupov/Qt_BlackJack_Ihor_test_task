#pragma once

#include <QGraphicsView>

class BlackJackGame;
class CardItem;
class Hand;


class GameView: public QGraphicsView
{
    Q_OBJECT;
public:
    explicit GameView(QWidget* parent = nullptr);

    void updateFromGame(const BlackJackGame& game);

    static constexpr int CARD_WIDTH    = 60;
    static constexpr int CARD_HEIGHT   = 90;
    static constexpr int CARD_DISTANCE = 10;
    static constexpr double CARD_SCALE = 1.5;

private:
    void clearScene();
    int calculateHandWidth(int cardCount, int cardWidth, int space);
    void drawPlayerHand(const BlackJackGame& game);
    void drawDealerHand(const BlackJackGame& game);
    void drawHand(const Hand& hand, int y, bool hideSecondCard);
    void drawDeck();

protected:
    void resizeEvent(QResizeEvent* event) override;
    void showEvent(QShowEvent* event) override;

private:
    QGraphicsScene* scene_m;
    const BlackJackGame* game_m = nullptr;
};
