#include "gamemap.h"
#include <QFile>
#include <QRandomGenerator>

GameMap::GameMap() : gameState(GameState::RED_CAP)
{
    using namespace std;
    string words[25] = {"Рука", "Змея", "Телефон", "Иисус", "Дом",
                             "Родина", "Отчизна", "Клавиатура", "Москва", "Кружка",
                             "Стакан", "Мышка", "Университет", "Монитор", "Склад",
                             "Окно", "Нога", "Чайка", "Птица", "Конь",
                             "Танк", "Автомобиль", "Берлин", "Школа", "Санкт-Петербург"};
    QFile file(":/resources/dictionary.txt");
    file.open(QFile::ReadOnly);
    QString buff = file.readAll();
    QStringList dictionary = buff.split(",");

    for (int i = 0; i < 25; i++) {
        uint index = QRandomGenerator::global()->generate() % dictionary.size();
        QString temp = dictionary[QRandomGenerator::global()->generate() % dictionary.size()];
        temp[0] = temp[0].toUpper();
        dictionary.removeAt(index);
        words[i] = temp.toStdString();
    }
    vector <CardState> states = {CardState::NEUTRAL, CardState::BLUE,  CardState::RED,     CardState::RED,     CardState::BLUE,
                                 CardState::NEUTRAL, CardState::DEATH, CardState::RED,     CardState::BLUE,    CardState::RED,
                                 CardState::RED,     CardState::BLUE,  CardState::BLUE,    CardState::NEUTRAL, CardState::NEUTRAL,
                                 CardState::NEUTRAL, CardState::BLUE,  CardState::NEUTRAL, CardState::NEUTRAL, CardState::RED,
                                 CardState::NEUTRAL, CardState::BLUE,  CardState::RED,     CardState::BLUE,    CardState::NEUTRAL};
    random_shuffle(states.begin(), states.end(), [](int i) {return QRandomGenerator::global()->generate() % i;});

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
