#include "card.h"

Card::Card(std::string word, QColor color) : word(word), color(color)
{
    isPicked = false;
}
