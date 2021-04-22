#ifndef CARD_H
#define CARD_H
#include "string"
#include <QColor>
#include "utils.h"

class Card
{
public:
    Card();
    Card(std::string word, CardState cardState);
    std::string getString() { return word; };
    CardState getState() { return cardState; };
    bool isPicked();
    void pick();
    void changeState(GameState);

private:
    std::string word;
    CardState cardState;
    bool picked;
};

#endif // CARD_H
