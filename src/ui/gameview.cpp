#include "gameview.h"
#include "ui/carditem.h"
#include "logic/blackjackgame.h"

#include <QGraphicsScene>

static constexpr int CARD_WIDTH    = 120;
static constexpr int CARD_HEIGHT   = 180;
static constexpr int CARD_DISTANCE = 140;


GameView::GameView(QWidget* parent):
    QGraphicsView(parent),
    scene_m(new QGraphicsScene(this))
{
    scene_m->setBackgroundBrush(QBrush(Qt::darkGreen));

    setScene(scene_m);
    scene_m->setSceneRect(0, 0, 800, 600);
    setAlignment(Qt::AlignCenter);
}

void GameView::updateFromGame(const BlackJackGame& game)
{
    clearScene();

    drawDealerHand(game);
    drawPlayerHand(game);
    drawDeck();

    //QRectF itemsRect = scene_m->itemsBoundingRect();

//    QRectF cardsRect;
//    for (auto* item : scene_m->items())
//    {
//        if(dynamic_cast<CardItem*>(item))
//        {
//            cardsRect |= item->boundingRect().translated(item->pos());
//        }
//    }
//    if(!cardsRect.isEmpty())
//    {
//        fitInView(cardsRect, Qt::IgnoreAspectRatio);
//    }

    //if(!itemsRect.isEmpty())
    //{
    //    fitInView(itemsRect, Qt::KeepAspectRatio);
    //}
    //scene_m->addRect(0, 0, 800, 600, QPen(Qt::red));
    setAlignment(Qt::AlignCenter);
}

void GameView::clearScene()
{
    scene_m->clear();
}

void GameView::drawPlayerHand(const BlackJackGame& game)
{
    const Hand& hand = game.playerHand();
    int x = 200;
    int y = 350;

    for (const Card& card : hand.getCards())
    {
        auto* item = new CardItem(card, 0.3); //new
        item->setPos(x, y);
        scene_m->addItem(item);
        x+= CARD_DISTANCE;
    }
    qDebug() << "Player hand size:" << hand.getCards().size();
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
        auto* item = new CardItem(card, 0.3);

        if(index == 1 && hideSecondCard)
        {
            item->setCardSid(false);
        }

        item->setPos(x, y);
        scene_m->addItem(item);
        x+= CARD_DISTANCE;
        ++index;
    }
    qDebug() << "Dealer hand size: "<<hand.getCards().size();

}

void GameView::drawDeck()
{
    QPixmap back(":/cards/assets/cards/PNG/card_back.png");
    auto* item = new QGraphicsPixmapItem(back);

    item->setScale(0.3);
    item->setPos(600, 200);
    scene_m->addItem(item);
    for (int i = 1; i < 3; ++i)
    {
        auto* stackOfCards = new QGraphicsPixmapItem(back);
        stackOfCards->setScale(0.3);
        stackOfCards->setPos(600+i*2, 200+i*2);
        scene_m->addItem(stackOfCards);
    }
}
