#ifndef CARD_H
#define CARD_H
#include "string"
#include <QColor>


class Card
{
public:
    Card(std::string word, QColor color);
    std::string getString();
    QColor getColor();
    bool isPicked();
    void pick();
    void changeColor(QColor);

private:
    std::string word;
    QColor color;
    bool picked;
};

#endif // CARD_H
