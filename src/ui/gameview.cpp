#include "gameview.h"
#include "ui/carditem.h"
#include "logic/blackjackgame.h"

#include <QGraphicsScene>




GameView::GameView(QWidget* parent):
    QGraphicsView(parent),
    scene_m(new QGraphicsScene(this))
{
    scene_m->setBackgroundBrush(QBrush(Qt::darkGreen));

    setScene(scene_m);
    setAlignment(Qt::AlignCenter);
}

void GameView::updateFromGame(const BlackJackGame& game)
{
    game_m = &game;
    clearScene();

    drawDealerHand(game);
    drawPlayerHand(game);
    drawDeck();

    switch (game.gameResult())
    {
    case GameResult::PlayerWin:
        scene_m->addText("Player Wins!", QFont("Arial", 24))->setPos(500, 15);
        break;
    case GameResult::DealerWin:
        scene_m->addText("Dealer Wins!", QFont("Arial", 24))->setPos(500, 15);
        break;
    case GameResult::NoWinner:
        scene_m->addText("NoWinner (Draw)", QFont("Arial", 24))->setPos(500, 15);
        break;
    default:
        break;
    }

    setAlignment(Qt::AlignCenter);
}

void GameView::resizeEvent(QResizeEvent* event)
{
    QGraphicsView::resizeEvent(event);
    scene_m->setSceneRect(rect());
}

void GameView::showEvent(QShowEvent *event)
{
    QGraphicsView::showEvent(event);
    scene_m->setSceneRect(rect());

    if(game_m)
    {
        updateFromGame(*game_m);
    }
}

void GameView::clearScene()
{
    scene_m->clear();
}

int GameView::calculateHandWidth(int cardCount, int cardWidth, int space)
{
    if(cardCount == 0)
    {
        return 0;
    }

    int realCardWidth = cardWidth * CARD_SCALE;
    return cardCount*realCardWidth + (cardCount-1) * space;
}

void GameView::drawPlayerHand(const BlackJackGame& game)
{
    int y = scene_m->height() - CARD_HEIGHT * CARD_SCALE  - 50;
    drawHand(game.playerHand(), y, false);

    scene_m->addText(QString("Player: %1").arg(game.playerHand().calculateScore()),
                     QFont("Arial", 16))->setPos(50, y + CARD_HEIGHT - 50);

}

void GameView::drawDealerHand(const BlackJackGame& game)
{
    int y = 50;
    bool hideSecondCard = (game.gameState() == GameState::PlayerTurn);
    drawHand(game.dealerHand(), y, hideSecondCard);

    scene_m->addText(QString("Dealer: %1").arg(game.dealerHand().calculateScore()),
                     QFont("Arial", 16))->setPos(50, y + CARD_HEIGHT * CARD_SCALE - 100);

}

void GameView::drawHand(const Hand &hand, int y, bool hideSecondCard)
{
    int handWidth = calculateHandWidth(hand.getCards().size(), CARD_WIDTH, CARD_DISTANCE);
    int startX = (scene_m->width()-handWidth)/2;

    int index = 0;
    for (const Card& card : hand.getCards())
    {
        auto* item = new CardItem(card,  nullptr);
        if(index == 1 && hideSecondCard)
        {
            item->setCardSid(false);
        }

        item->setPos(startX, y);
        scene_m->addItem(item);
        startX += CARD_WIDTH * CARD_SCALE + CARD_DISTANCE;
        ++index;
    }
}

void GameView::drawDeck()
{
    QPixmap back(":/cards/assets/cards/PNG/card_back.png");

    back = back.scaled(GameView::CARD_WIDTH * CARD_SCALE,
                       GameView::CARD_HEIGHT * CARD_SCALE,
                       Qt::KeepAspectRatio,
                       Qt::SmoothTransformation);

    int baseX = 1000;
    int baseY = 300;

    auto* item = new QGraphicsPixmapItem(back);
    item->setPos(baseX, baseY);
    scene_m->addItem(item);

    for (int i = 1; i < 3; ++i)
    {
        auto* stackOfCards = new QGraphicsPixmapItem(back);
        stackOfCards->setPos(baseX + i*2, baseY + i*2);
        scene_m->addItem(stackOfCards);
    }

}
