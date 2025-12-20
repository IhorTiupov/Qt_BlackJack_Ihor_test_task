#pragma once

#include <vector>
//#include <cstddef>

#include "card.h"

class Hand
{
public:
    Hand() = default;

    void addCard(const Card& card);
    void clear();
    int calculateScore() const;
    bool isBust() const;
    bool hasBlackJack() const;
    std::size_t cardsCount()const;
    const std::vector<Card>& getCards()const;
private:
    std::vector<Card> handCards_m;

};

