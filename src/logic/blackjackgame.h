#pragma once

#include "deck.h"
#include "hand.h"


enum class GameState
{
    ReadyToStart,
    PlayerTurn,
    DealerTurn,
    Finihed
};

enum class GameResult
{
    None,
    PlayerWin,
    DealerWin,
    NoWinner
};

class BlackJackGame
{
public:
    BlackJackGame();

    void startNewGame();
    void playerHit();
    void playerStand();

    GameState  gameState()const;
    GameResult gameResult()const;

    const Hand& playerHand() const;
    const Hand& dealerHand() const;

private:
    void dealerPlay();
    void checkWinner();

private:
    Deck       deck_m;
    Hand       playerHand_m;
    Hand       dealerHand_m;
    GameState  stateGame_m;
    GameResult resultGame_m;
};

