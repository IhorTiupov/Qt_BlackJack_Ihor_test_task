#pragma once

#include <QString>
#include "hand.h"


class Player
{
public:
    Player(const QString& name);

    Hand& hand();

    const Hand& hand()const;
    QString name() const;

    void clearHand();

private:
    QString playerName_m;
    Hand playerHand_m;
};

