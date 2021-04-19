#ifndef LOCALCONTROLLER_H
#define LOCALCONTROLLER_H

#include <icontroller.h>

class LocalController : public IController
{
    Session session;
public:
    GameMap initRequest() override;
    GameMap request(int) override;
    Session getSession() override;
};

#endif // LOCALCONTROLLER_H
