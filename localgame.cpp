#include "localgame.h"
#include "qdebug.h"

LocalGame::LocalGame()
{
    gameMap = new GameMap();
}

GameMap* LocalGame::turn(int ID)
{

    qDebug() << ID;
    return gameMap;
}

GameMap *LocalGame::init()
{
    return gameMap;
}
