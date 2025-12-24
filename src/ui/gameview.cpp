#include "gameview.h"
#include "ui/carditem.h"
#include "logic/blackjackgame.h"

#include <QGraphicsScene>

static constexpr int CARD_WIDTH    = 120;
static constexpr int CARD_HEIGHT   = 180;
static constexpr int CARD_DISTANCE = 30;



GameView::GameView(QWidget* parent):
    QGraphicsView(parent),
    scene_m(new QGraphicsScene(this))
{
    setScene(scene_m);
    //setRenderHint(QPainter::Antialiasing); //anti‑aliasing - on
}

void GameView::updateFromGame(const BlackJackGame& game)
{
    clearScene();
    drawDealerHand(game);
    drawPlayerHand(game);
}

void GameView::clearScene()
{
    scene_m->clear();
}

void GameView::drawPlayerHand(const BlackJackGame& game)
{
    const Hand& hand = game.playerHand();
    int x = 100;
    int y = 300;

    for (const Card& card : hand.getCards())
    {
        auto* item = new CardItem(card);
        item->setPos(x, y);
        scene_m->addItem(item);
        x+= CARD_DISTANCE;
    }
}

void GameView::drawDealerHand(const BlackJackGame& game)
{
    const Hand& hand = game.dealerHand();
    int x = 100;
    int y = 50;

    bool hideSecondCard;
    if(game.gameState() == GameState::PlayerTurn)
    {
        hideSecondCard = true;
    }
    else
    {
        hideSecondCard = false;
    }

    int index = 0;
    for (const Card& card : hand.getCards())
    {
        auto* item = new CardItem(card);

        if(index == 1 && hideSecondCard)
        {
            item->setCardSid(false);
        }

        item->setPos(x, y);
        scene_m->addItem(item);
        x+= CARD_DISTANCE;
        ++index;
    }


}
