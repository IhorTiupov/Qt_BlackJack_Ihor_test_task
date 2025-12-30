#include "blackjackgame.h"

BlackJackGame::BlackJackGame():
    player_m("Player"),
    dealer_m("Dealer"),
    stateGame_m(GameState::ReadyToStart),
    resultGame_m(GameResult::None)
{}

void BlackJackGame::startNewGame()
{
    deck_m = Deck();
    deck_m.shuffleCards();

    player_m.clearHand();
    dealer_m.clearHand();

    player_m.hand().addCard(deck_m.drawCard());
    dealer_m.hand().addCard(deck_m.drawCard());

    player_m.hand().addCard(deck_m.drawCard());
    dealer_m.hand().addCard(deck_m.drawCard());

    stateGame_m  = GameState ::PlayerTurn;
    resultGame_m = GameResult::None;

    if(player_m.hand().hasBlackJack() || dealer_m.hand().hasBlackJack() )
    {
        stateGame_m = GameState::Finished;
        checkWinner();
    }
}

void BlackJackGame::playerHit()
{
    if(stateGame_m != GameState::PlayerTurn)
    {
        return;
    }

    player_m.hand().addCard(deck_m.drawCard());

    if(player_m.hand().isBust())
    {
        stateGame_m = GameState::Finished;
        checkWinner();
    }
}

void BlackJackGame::playerStand()
{
    if(stateGame_m != GameState::PlayerTurn)
    {
        return;
    }

    stateGame_m = GameState::DealerTurn;
    dealerPlay();

    //if(dealer_m.hand().isBust() || dealer_m.hand().calculateScore() >= 17)
    //{
    checkWinner();
    //}
}

GameState BlackJackGame::gameState() const
{
    return stateGame_m;
}

GameResult BlackJackGame::gameResult() const
{
    return resultGame_m;
}

const Hand &BlackJackGame::playerHand() const
{
    return player_m.hand();
}

const Hand &BlackJackGame::dealerHand() const
{
    return dealer_m.hand();
}

void BlackJackGame::dealerPlay()
{
    while (dealer_m.hand().calculateScore() < 17)
    {
        dealer_m.hand().addCard(deck_m.drawCard());
    }
}

void BlackJackGame::checkWinner()
{
    int playerScore = player_m.hand().calculateScore();
    int dealerScore = dealer_m.hand().calculateScore();

    if(player_m.hand().isBust())
    {
        resultGame_m = GameResult::DealerWin;
    }
    else if(dealer_m.hand().isBust())
    {
        resultGame_m = GameResult::PlayerWin;
    }
    else if(playerScore > dealerScore)
    {
        resultGame_m = GameResult::PlayerWin;
    }
    else if(dealerScore > playerScore)
    {
        resultGame_m = GameResult::DealerWin;
    }
    else
    {
        resultGame_m = GameResult::NoWinner;
    }
    stateGame_m = GameState::Finished;
}

void BlackJackGame::showDealerCards()
{
    if(stateGame_m == GameState::DealerTurn)
    {
        checkWinner();
    }
}

std::pair<int, int> BlackJackGame::currentScores() const
{
    return {player_m.hand().calculateScore(), dealer_m.hand().calculateScore()};
}
