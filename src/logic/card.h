#pragma once
#include <string>


enum class Suit
{
    Hearts,
    Diamonds,
    Clubs,
    Spades
};

enum class Rank
{
    Two = 2,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

struct Card
{
    Suit suit;
    Rank rank;

    int value() const
    {
        if(rank >= Rank::Two && rank <= Rank::Ten)
        {
            return static_cast<int>(rank);
        }

        if(rank == Rank::Ace)
        {
            return 11;
        }
        return 10;
    }
};


