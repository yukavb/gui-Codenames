#include "localgame.h"
#include "qdebug.h"

LocalGame::LocalGame()
{
    gameMap = new GameMap();
}

GameMap* LocalGame::turn(int ID)
{
    if (gameMap->cards[ID].isPicked()) {
        return gameMap;
    }
    count--;

    switch (gameMap->getState()) {
        case GameState::RED_TEAM:
            if (!count) gameMap->gameState = GameState::BLUE_CAP;
            gameMap->cards[ID].pick();
            break;

        case GameState::BLUE_TEAM:
            if (!count) gameMap->gameState = GameState::RED_CAP;
            gameMap->cards[ID].pick();
            break;

        case GameState::RED_CAP:
        case GameState::BLUE_CAP:
            break;
    }
    return gameMap;
}

GameMap* LocalGame::turn(std::string word, int count) {
    this->count = count;

    switch (gameMap->getState()) {
        case GameState::RED_CAP:
            gameMap->gameState = GameState::RED_TEAM;
            break;

        case GameState::BLUE_CAP:
            gameMap->gameState = GameState::BLUE_TEAM;
            break;

        case GameState::RED_TEAM:
        case GameState::BLUE_TEAM:
            break;
    }

    return gameMap;
}

GameMap *LocalGame::init()
{
    return gameMap;
}
