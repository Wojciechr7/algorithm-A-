#ifndef STEP_H
#define STEP_H
#include "Target.h";
#include <iostream>
#include <math.h>


class Step
{
    public:
        Step(int x, int y, int pX, int pY);
        Step(int x, int y);
        virtual ~Step();
        int x, y;
        int parentX, parentY;
        float h;

        float calculateDistance(Target t, int G) {
            h = G + sqrt(pow(t.pos.x - x, 2) + pow(t.pos.y - y, 2));
            return h;
        }

    protected:

    private:
};

#endif // STEP_H
