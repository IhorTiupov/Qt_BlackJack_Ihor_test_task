#include "carditem.h"
#include <QString>
#include <QMap> //new

static QMap<QString, QPixmap> pixmapCache;

CardItem::CardItem(const Card& card,qreal scale, QGraphicsItem* parent): //new
    QGraphicsPixmapItem(parent),
    card_m(card),
    faceSideCard_m(true),
    scale_m(scale) //new
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
        return QString("%1").arg(static_cast<int>(rank), 2, 10, QChar('0'));
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

QPixmap CardItem::loadPixmap(const QString& path) // new
{
    if(pixmapCache.contains(path))
    {
        return pixmapCache[path];
    }
    QPixmap pix(path);
    pixmapCache[path] = pix;
    return pix;
}

void CardItem::updatePixmap()
{
    QString path;

    if(faceSideCard_m)
    {
        path = QString(":/cards/assets/cards/PNG/card_%1_%2.png").
               arg(suitToString(card_m.suit)).
               arg(rankToString(card_m.rank));
        qDebug() << "Loading pixmap:" << path;
    }
    else
    {
        path = ":/cards/assets/cards/PNG/card_back.png";
    }
    QPixmap pix = loadPixmap(path); //new
    if(pix.isNull())
    {
        qDebug() << "pixmap is NULL for path: " << path;
    }
    else
    {
        qDebug() << "pixmap loaded: " << path;
    }
    setPixmap(QPixmap(pix)); //new
    setScale(0.4);
    qDebug() << "Card scale: " << scale_m;
    qDebug() << "Loading pixmap: " << path;

}

