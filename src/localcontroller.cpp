#include "localcontroller.h"
#include "qdebug.h"

LocalController::LocalController() {
    localGame = new LocalGame();
}

const GameMap* LocalController::initRequest() {
    GameMap* gameMap = localGame->init();
    return gameMap;
}

const GameMap* LocalController::request() {
    return localGame->gameMap;
}

const GameMap* LocalController::request(int id) {
    GameMap* gameMap = localGame->turn(id);
    return gameMap;
}

const GameMap* LocalController::concede() {
    GameMap* gameMap = localGame->concede();
    return gameMap;
}

const GameMap* LocalController::request(std::string word, int count) {
    GameMap* gameMap = localGame->turn(word, count);
    return gameMap;
}

Session LocalController::getSession() {
    Session session;
    return session;
}
