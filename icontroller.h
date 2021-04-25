#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include <gamemap.h>
#include <session.h>

class IController
{
public:
    virtual const GameMap* initRequest() = 0;
    virtual const GameMap* request() = 0;
    virtual const GameMap* request(int) = 0;
    virtual const GameMap* request(std::string, int) = 0;
    virtual Session getSession() = 0;
};

#endif // ICONTROLLER_H
