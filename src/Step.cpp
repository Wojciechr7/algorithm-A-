#include "../include/Step.h"

Step::Step(int x, int y)
{
    //ctor
    Step::x = x;
    Step::y = y;
    Step::stepsBefore = 0;
}
Step::Step(int x, int y, Step& s)
{
    //ctor
    Step::x = x;
    Step::y = y;
    Step::prev = &s;
    Step::stepsBefore = prev->stepsBefore + 1;
}

Step::~Step()
{
    //dtor
}
