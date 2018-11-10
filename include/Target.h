#ifndef TARGET_H
#define TARGET_H
#include "Position.h"


class Target
{
    public:
        Target(int x, int y);
        virtual ~Target();
        Position pos;

    protected:
    private:
};

#endif // TARGET_H
