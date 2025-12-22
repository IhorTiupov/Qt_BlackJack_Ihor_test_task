#include "player.h"

Player::Player(const QString& name): playerName_m(name)
{}

Hand& Player::hand()
{
    return playerHand_m;
}

const Hand& Player::hand() const
{
    return playerHand_m;
}

QString Player::name() const
{
    return playerName_m;
}

void Player::clearHand()
{
    playerHand_m.clear();
}
