#ifndef LOCALGAME_H
#define LOCALGAME_H

#include <gamemap.h>

class LocalGame
{
public:
    GameMap* gameMap;
    LocalGame();
    GameMap* turn(int);
    GameMap* init();
};

#endif // LOCALGAME_H
