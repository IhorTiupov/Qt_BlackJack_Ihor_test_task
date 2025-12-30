#pragma once

#include "deck.h"
#include "hand.h"
#include "player.h"


enum class GameState
{
    ReadyToStart,
    PlayerTurn,
    DealerTurn,
    Finished
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
    void showDealerCards();
    std::pair<int, int> currentScores() const;

private:
    Deck       deck_m;
    Player     player_m;
    Player     dealer_m;
    GameState  stateGame_m;
    GameResult resultGame_m;
};

