#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include <gamemap.h>
#include <session.h>

class IController
{
public:
    virtual GameMap initRequest() = 0;
    virtual GameMap request(int) = 0;
    virtual Session getSession() = 0;
};

#endif // ICONTROLLER_H
