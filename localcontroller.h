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
    GameMap initRequest() override;
    GameMap request(int) override;
    Session getSession() override;
};

#endif // LOCALCONTROLLER_H
