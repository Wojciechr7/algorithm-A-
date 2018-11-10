#ifndef STEP_H
#define STEP_H
#include <iostream>
#include <math.h>
#include "Target.h"


class Step
{
    public:
        Step(int x, int y, int pX, int pY);
        Step(int x, int y);
        Step(int x, int y, Step& s);
        virtual ~Step();
        int x, y;
        int parentX, parentY;
        float h;
        Step* prev;
        int stepsBefore;

        float calculateDistance(Target& t) {
            h = stepsBefore + sqrt(pow(t.pos.x - x, 2) + pow(t.pos.y - y, 2));
            return h;
        }

        bool compare (Target t) {
            return x == t.pos.x && y == t.pos.y;
        }

    protected:

    private:
};

#endif // STEP_H
