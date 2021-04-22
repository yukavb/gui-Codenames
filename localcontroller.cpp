#include "localcontroller.h"
#include "qdebug.h"

LocalController::LocalController() {
    localGame = new LocalGame();
}

GameMap LocalController::initRequest() {
    GameMap* gameMap = localGame->init();
    return *gameMap;
}

GameMap LocalController::request(int id)
{
    GameMap* gameMap = localGame->turn(id);
    return *gameMap;
}

Session LocalController::getSession()
{
    Session session;
    return session;
}
