#ifndef LOCALGAME_H
#define LOCALGAME_H

#include <gamemap.h>

class LocalGame
{
    int count = 0;
public:
    GameMap* gameMap;
    LocalGame();
    GameMap* turn(int);
    GameMap* turn(std::string, int);
    GameMap* init();
};

#endif // LOCALGAME_H
