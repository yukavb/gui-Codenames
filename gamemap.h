#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "vector"
#include "card.h"
#include "utils.h"

class GameMap
{
public:
    friend class LocalGame;
    GameMap();
    Card getCard(int index) const { return cards[index]; };
    GameState getState() const { return gameState; };
    GameState nextTurn() const;

private:
    std::vector<Card> cards;
    GameState gameState;
};

#endif // GAMEMAP_H
