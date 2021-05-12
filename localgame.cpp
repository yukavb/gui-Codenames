#include "localgame.h"
#include "qdebug.h"

LocalGame::LocalGame()
{
    gameMap = new GameMap();
}

GameMap* LocalGame::turn(int ID)
{
    if (gameMap->cards[ID].isPicked() || gameMap->isCaptainTurn()
            || gameMap->isGameEnded() != EndState::NOT_END) {
        return gameMap;
    }
    gameMap->count--;
    Card &card = gameMap->cards[ID];
    GameState gameState = gameMap->getState();
    card.pick();

    if (card.getState() == CardState::RED) {
        gameMap->redCards--;
    } else if (card.getState() == CardState::BLUE) {
        gameMap->blueCards--;
    } else if (card.getState() == CardState::DEATH) {
        (gameState == GameState::BLUE_TEAM ? gameMap->redCards : gameMap->blueCards) = 0;

        if (gameState == GameState::BLUE_TEAM) {
            gameMap->gameState = GameState::RED_CAP;
        } else if (gameState == GameState::RED_TEAM) {
            gameMap->gameState = GameState::BLUE_CAP;
        }
        return gameMap;
    }

    if (gameState == GameState::RED_TEAM) {
        if (card.getState() != CardState::RED) {
            gameMap->count = 0;
        }

        if (!gameMap->count) {
            gameMap->gameState = GameState::BLUE_CAP;
        }
    } else if (gameState == GameState::BLUE_TEAM) {
        if (card.getState() != CardState::BLUE) {
            gameMap->count = 0;
        }

        if (!gameMap->count) {
            gameMap->gameState = GameState::RED_CAP;
        }
    }
    return gameMap;
}

GameMap* LocalGame::turn(std::string word, int count) {
    if (gameMap->isGameEnded() != EndState::NOT_END) {
        return gameMap;
    }
    gameMap->count = count;

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

GameMap* LocalGame::init()
{
    return gameMap;
}

GameMap* LocalGame::concede()
{
    GameState gameState = gameMap->getState();
    ((gameState == GameState::BLUE_TEAM || gameState == GameState::BLUE_CAP) ? gameMap->redCards : gameMap->blueCards) = 0;
    return gameMap;
}
