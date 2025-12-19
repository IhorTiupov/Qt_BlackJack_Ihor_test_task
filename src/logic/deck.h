#pragma once

#include <vector>
#include "card.h"


class Deck
{
public:
    Deck();

    void shuffleCards();
    Card drawCard();
    bool isDeckEmpty() const;
    std::size_t currentSizeDeck() const;

private:
    std::vector<Card> cards_m;
};

