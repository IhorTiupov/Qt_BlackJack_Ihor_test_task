#include "carditem.h"
#include <QString>

CardItem::CardItem(const Card& card, QGraphicsItem* parent):
    QGraphicsPixmapItem(parent),
    card_m(card),
    faceSideCard_m(true)
{
    updatePixmap();
}

QString CardItem::suitToString(Suit suit)
{
    switch (suit)
    {
    case Suit::Clubs:    return "clubs";
    case Suit::Diamonds: return "diamonds";
    case Suit::Hearts:   return "hearts";
    case Suit::Spades:   return "spades";
    }
    return {};
}

QString CardItem::rankToString(Rank rank)
{
    switch (rank)
    {
    case Rank::Ace:   return "ace";
    case Rank::King:  return "king";
    case Rank::Queen: return "queen";
    case Rank::Jack:  return "jack";
    default:
        return QString::number(static_cast<int>(rank));
    }
}

void CardItem::setCardSid(bool cardSid)
{
    faceSideCard_m = cardSid;
    updatePixmap();
}

bool CardItem::isFaceCardUp() const
{
    return faceSideCard_m;
}

void CardItem::updatePixmap()
{
    QString path;

    if(faceSideCard_m)
    {
        path = QString(":/cards/assets/cards/PNG/card_%1_%2.png").
               arg(suitToString(card_m.suit)).
               arg(rankToString(card_m.rank));
    }
    else
    {
        path = ":/cards/assets/cards/PNG/card_back.png";
    }

    setPixmap(QPixmap(path));
}

