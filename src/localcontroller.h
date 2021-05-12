#ifndef LOCALCONTROLLER_H
#define LOCALCONTROLLER_H

#include <icontroller.h>
#include "localgame.h"

class LocalController : public IController
{
    Session session;
    LocalGame* localGame;

public:
    LocalController();
    const GameMap* initRequest() override;
    const GameMap* request() override;
    const GameMap* request(int) override;
    const GameMap* request(std::string, int) override;
    Session getSession() override;
    const GameMap *concede();
};

#endif // LOCALCONTROLLER_H
