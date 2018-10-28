#include <iostream>
#include "include/Board.h";
#include "include/Robot.h";
#include "include/Target.h";
#include "include/Step.h";
#include <list>
#include <algorithm>

using namespace std;


    void displayList(list<Step> l);
    Step findShortestMove(list<Step> O, Target t, list<Step> Z);

int main()
{

    Board board;

    list<Step> Z;
    list<Step> O;

    Robot robot(0, 0);

    Z.push_back(Step(robot.pos.x, robot.pos.y));
    board.G[0][0] = 1;

    Target target(19, 19);


    while (!robot.compare(target)) {
        O = board.findAvailableMoves(robot);

        Z.push_back(findShortestMove(O, target, Z));
        robot.switchPosition(Z.back());
        board.signStep(Z.back());



    }


    board.writeBoard();
    displayList(Z);




    return 0;
}




    void displayList(list<Step> l) {
            list <Step> :: iterator it;
            cout << endl << "list:" << endl;
            for(it = l.begin(); it != l.end(); ++it)
            cout  << "x: " << it->x << " y: " << it->y << endl;

            cout << "-------------------" << endl;
        }




    Step findShortestMove(list<Step> O, Target t, list<Step> Z) {
        list <Step> :: iterator it;
        float* distances = new float[4];
        int G = Z.size();

        int index = 0;
        for(it = O.begin(); it != O.end(); ++it) {
            distances[index++] = it->calculateDistance(t, G);

        }

        for (int i = 0; i < index; i++) {
            if (distances[i] == *min_element(distances, distances + index)) {
                for(it = O.begin(); it != O.end(); ++it) {
                    if (distances[i] == it->h) {
                        return *it;
                    }
                }
            }
        }
    }


