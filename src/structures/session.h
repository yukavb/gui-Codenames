#ifndef SESSION_H
#define SESSION_H


class Session
{
public:
    Session(int id = 0) : sessionID(id) {}
    unsigned int getID() { return sessionID; };

private:
    unsigned int sessionID;
};

#endif // SESSION_H
