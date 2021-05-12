#ifndef UTILS_H
#define UTILS_H

enum class CardState {
    BLUE,
    RED,
    NEUTRAL,
    DEATH,
};

enum class GameState {
    BLUE_TEAM,
    RED_TEAM,
    BLUE_CAP,
    RED_CAP
};

enum class EndState {
    RED_WINS,
    BLUE_WINS,
    NOT_END
};

#endif // UTILS_H
