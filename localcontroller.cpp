#include "localcontroller.h"
#include "qdebug.h"

LocalController::LocalController() {
    localGame = new LocalGame();
}

GameMap LocalController::initRequest() {
    GameMap* gameMap = localGame->init();
    return *gameMap;
}

GameMap LocalController::request() {
    return *localGame->gameMap;
}

GameMap LocalController::request(int id)
{
    GameMap* gameMap = localGame->turn(id);
    return *gameMap;
}

GameMap LocalController::request(std::string word, int count)
{
    GameMap* gameMap = localGame->turn(word, count);
    return *gameMap;
}

Session LocalController::getSession()
{
    Session session;
    return session;
}
