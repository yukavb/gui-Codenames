#include "card.h"

Card::Card()
{
    word = "123";
    cardState = CardState::NEUTRAL;
}

Card::Card(std::string word, CardState cardState) : word(word), cardState(cardState), picked(false)
{}

void Card::pick() {
    picked = true;
}

bool Card::isPicked() const {
    return picked;
}
