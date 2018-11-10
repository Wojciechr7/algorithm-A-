#ifndef ROBOT_H
#define ROBOT_H
#include <list>
#include "Position.h"
#include "Step.h"



class Robot
{
    public:
        Robot(int x, int y);
        virtual ~Robot();
        Position pos;
        std::list<Step> bestRoute;

        void switchPosition(Step s) {
            pos.x = s.x;
            pos.y = s.y;
        }

        void calculateBestRoute(Step* last, double **G) {

            bestRoute.push_front(*last);

            if (!(last->x == pos.x && last->y == pos.y)) {
                return calculateBestRoute(last->prev, G);
            }
        }

    protected:
    private:
};

#endif // ROBOT_H
