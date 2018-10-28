#ifndef ROBOT_H
#define ROBOT_H
#include "Position.h";
#include "Step.h";
#include "Target.h";


class Robot
{
    public:
        Robot(int x, int y);
        virtual ~Robot();
        Position pos;

        void switchPosition(Step s) {
            pos.x = s.x;
            pos.y = s.y;
        }

        bool compare (Target t) {
            return pos.x == t.pos.x && pos.y == t.pos.y;
        }
    protected:
    private:
};

#endif // ROBOT_H
