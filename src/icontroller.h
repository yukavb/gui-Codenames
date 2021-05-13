#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include <src/structures/gamemap.h>
#include <src/structures/session.h>

class IController
{
public:
    virtual const GameMap* concede() = 0;
    virtual const GameMap* initRequest() = 0;
    virtual const GameMap* request() = 0;
    virtual const GameMap* request(int) = 0;
    virtual const GameMap* request(std::string, int) = 0;
    virtual Session getSession() = 0;
};

#endif // ICONTROLLER_H
