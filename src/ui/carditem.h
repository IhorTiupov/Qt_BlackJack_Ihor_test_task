#pragma once

#include <QGraphicsPixmapItem>
#include "logic/card.h"

class CardItem: public QGraphicsPixmapItem
{
public:
    CardItem(const Card& card, QGraphicsItem* parent = nullptr);

    static QString suitToString(Suit suit);
    static QString rankToString(Rank rank);

    void setCardSid(bool cardSid);
    bool isFaceCardUp() const;

private:
    QPixmap loadPixmap(const QString& path);//new
    void updatePixmap();

private:
    Card card_m;
    bool faceSideCard_m;
};

