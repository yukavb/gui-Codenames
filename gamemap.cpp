#include "gamemap.h"

GameMap::GameMap() : gameState(GameState::RED_CAP)
{
    std::string words[25] = {"Рука", "Змея", "Телефон", "Иисус", "Дом",
                             "Родина", "Отчизна", "Клавиатура", "Москва", "Кружка",
                             "Стакан", "Мышка", "Университет", "Монитор", "Склад",
                             "Окно", "Нога", "Чайка", "Птица", "Конь",
                             "Танк", "Автомобиль", "Берлин", "Школа", "Санкт-Петербург"};
    CardState states[25] = {CardState::NEUTRAL, CardState::BLUE,  CardState::RED,     CardState::RED,     CardState::BLUE,
                                    CardState::NEUTRAL, CardState::DEATH, CardState::RED,     CardState::BLUE,    CardState::RED,
                                    CardState::RED,     CardState::BLUE,  CardState::BLUE,    CardState::NEUTRAL, CardState::NEUTRAL,
                                    CardState::NEUTRAL, CardState::BLUE,  CardState::NEUTRAL, CardState::NEUTRAL, CardState::RED,
                                    CardState::NEUTRAL, CardState::BLUE,  CardState::RED,     CardState::BLUE,    CardState::NEUTRAL};

    for (int i = 0; i < 25; i++) {
        cards.emplace_back(words[i], states[i]);
    }
}

EndState GameMap::isGameEnded() const {
    if (redCards == 0) {
        return EndState::RED_WINS;
    } else if (blueCards == 0) {
        return EndState::BLUE_WINS;
    }
    return EndState::NOT_END;
}
