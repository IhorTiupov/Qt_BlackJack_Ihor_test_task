#include "hand.h"

void Hand::addCard(const Card& card)
{
    handCards_m.push_back(card);
}

void Hand::clear()
{
    handCards_m.clear();
}

int Hand::calculateScore() const
{
    int totalScore = 0;
    int aceCount = 0;
    for(const Card& card: handCards_m)
    {
        totalScore +=card.value();
        if(card.rank == Rank::Ace)
        {
            ++aceCount;
        }
        while (totalScore > 21 && aceCount > 0)
        {
            totalScore -=10;
            --aceCount;
        }
    }
    return totalScore;
}

bool Hand::isBust() const
{
    return (calculateScore() > 21);
}

bool Hand::hasBlackJack() const
{
    return (handCards_m.size() == 2 && calculateScore() == 21);
}

std::size_t Hand::cardsCount() const
{
    return handCards_m.size();
}

const std::vector<Card>& Hand::getCards() const
{
    return handCards_m;
}
