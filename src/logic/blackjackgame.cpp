#include "blackjackgame.h"

BlackJackGame::BlackJackGame(): stateGame_m(GameState::ReadyToStart),
                                resultGame_m(GameResult::None)
{}

void BlackJackGame::startNewGame()
{
    deck_m = Deck();
    deck_m.shuffleCards();

    playerHand_m.clear();
    dealerHand_m.clear();

    playerHand_m.addCard(deck_m.drawCard());
    dealerHand_m.addCard(deck_m.drawCard());

    playerHand_m.addCard(deck_m.drawCard());
    dealerHand_m.addCard(deck_m.drawCard());

    stateGame_m  = GameState::PlayerTurn;
    resultGame_m = GameResult::None;

    if(playerHand_m.hasBlackJack())
    {
        stateGame_m=GameState::Finihed;
        checkWinner();
    }
}

void BlackJackGame::playerHit()
{
    if(stateGame_m != GameState::PlayerTurn)
    {
        return;
    }

    playerHand_m.addCard(deck_m.drawCard());

    if(playerHand_m.isBust())
    {
        stateGame_m = GameState::Finihed;
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
    checkWinner();
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
    return playerHand_m;
}

const Hand &BlackJackGame::dealerHand() const
{
    return dealerHand_m;
}

void BlackJackGame::dealerPlay()
{
    while (dealerHand_m.calculateScore())
    {
        dealerHand_m.addCard(deck_m.drawCard());
    }
}

void BlackJackGame::checkWinner()
{
    int playerScore = playerHand_m.calculateScore();
    int dealerScore = dealerHand_m.calculateScore();

    if(playerHand_m.isBust())
    {
        resultGame_m = GameResult::DealerWin;
    }
    else if(dealerHand_m.isBust())
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
    stateGame_m = GameState::Finihed;
}
