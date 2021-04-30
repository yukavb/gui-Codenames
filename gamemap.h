#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "vector"
#include "card.h"
#include "utils.h"

class GameMap
{
    int count = 0;
    int redCards = 7;
    int blueCards = 8;
public:
    friend class LocalGame;
    GameMap();
    Card getCard(int index) const { return cards[index]; };
    GameState getState() const { return gameState; };
    bool isCaptainTurn() const { return gameState == GameState::RED_CAP || gameState == GameState::BLUE_CAP; };
    bool isTeamTurn() const { return !isCaptainTurn(); };
    int getCountWordsOnTurn() const { return count; };
    EndState isGameEnded()  const;

private:
    std::vector<Card> cards;
    GameState gameState;
};

#endif // GAMEMAP_H
