#include "../include/Step.h"

Step::Step(int x, int y, int pX, int pY)
{
    //ctor
    Step::x = x;
    Step::y = y;
    Step::parentX = pX;
    Step::parentY = pY;
}
Step::Step(int x, int y)
{
    //ctor
    Step::x = x;
    Step::y = y;
}

Step::~Step()
{
    //dtor
}
