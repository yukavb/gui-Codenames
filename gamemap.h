#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "vector"
#include "card.h"
#include "utils.h"

class GameMap
{

public:
    GameMap();
    Card getCard(int index) { return cards[index]; };
    void pickCard(int index);
    GameState getState() { return gameState; };
    GameState nextTurn();

private:
    std::vector<Card> cards;
    GameState gameState;
};

#endif // GAMEMAP_H
