#include "deck.h"

#include<algorithm>
#include<random>
#include<stdexcept>

Deck::Deck()
{
    cards_m.reserve(52);
    for (int suit  = static_cast<int>(Suit::Hearts);
             suit <= static_cast<int>(Suit::Spades);
           ++suit)
    {
        for (int rank  = static_cast<int>(Rank::Two);
                 rank <= static_cast<int>(Rank::Ace)
             ; ++rank)
        {
            cards_m.push_back({static_cast<Suit>(suit),
                               static_cast<Rank>(rank)});
        }
    }
}

void Deck::shuffleCards()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::shuffle(cards_m.begin(), cards_m.end(), gen);
}

Card Deck::drawCard()
{
    if (cards_m.empty())
    {
        throw std::runtime_error("Deck is empty");
    }

    Card card = cards_m.back();
    cards_m.pop_back();
    return card;
}

bool Deck::isDeckEmpty() const
{
    return cards_m.empty();
}

std::size_t Deck::currentSizeDeck()const
{
    return cards_m.size();
}
