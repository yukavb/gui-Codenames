#ifndef CARD_H
#define CARD_H
#include "string"
#include <QColor>


class Card
{
public:
    Card(std::string word, QColor color);

private:
    std::string word;
    QColor color;
    bool isPicked;
};

#endif // CARD_H
