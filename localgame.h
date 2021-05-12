#ifndef LOCALGAME_H
#define LOCALGAME_H

#include <gamemap.h>

class LocalGame
{
public:
    GameMap* gameMap;
    LocalGame();
    GameMap* init();
    int countWordsOnTurn();
    GameMap* turn(int);
    GameMap* turn(std::string, int);
    GameMap* nextTurn();
    GameMap *concede();
};

#endif // LOCALGAME_H
