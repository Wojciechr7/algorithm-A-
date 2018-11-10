#include <iostream>
#include "include/Board.h"
#include "include/Robot.h"
#include "include/Target.h"
#include "include/Step.h"
#include <list>
#include <algorithm>
#include <vector>

using namespace std;


    void displayList(list<Step> l);
    Step findShortestMove(list<Step>& O, Target& t, int G);

int main()
{

    Board board;

    list<Step> Z;
    list<Step> O;
    bool noWay = false;

    Robot robot(0, 0);
    Target target(19, 19);

    Step firstStep(robot.pos.x, robot.pos.y);
    firstStep.calculateDistance(target);
    Z.push_back(firstStep);

    list<Step> mv;

    while (!Z.back().compare(target)) {

        mv = board.findAvailableMoves(Z, target, O);

        O.splice(O.end(), mv);

        if (O.size() == 0) {
            noWay = true;
            break;
        }

        Z.push_back(findShortestMove(O, target, Z.size()));
    }

    if (!noWay) {
        robot.calculateBestRoute(&Z.back(), board.G);
        board.signSteps(robot.bestRoute);
        board.writeBoard();
        displayList(robot.bestRoute);

    } else {
        board.writeBoard();
        cout << "\n\nBrak mozliwosci przejscia\n\n";
    }

    return 0;
}




    void displayList(list<Step> l) {
            list <Step> :: iterator it;
            cout << endl << "list:" << endl;
            for(it = l.begin(); it != l.end(); ++it) {
                if(it->x == 0 && it->y == 0) {
                    cout  << "x: " << it->x << " y: " << it->y << endl;
                } else {
                    cout  << "x: " << it->x << " y: " << it->y << " parentX: " << it->prev->x << " parentY: " << it->prev->y << endl;
                }
            }
            cout << "-------------------" << endl;
        }


    Step findShortestMove(list<Step>& O, Target& t, int G) {
        list <Step> :: iterator it;

        vector<float> distances;

        for(it = O.begin(); it != O.end(); ++it) {
            distances.push_back(it->h);
        }

        int index = distances.size();

        for (int i = 0; i < index; i++) {
            if (distances[i] == *min_element(distances.begin(), distances.end())) {
                for(it = O.begin(); it != O.end(); ++it) {
                    if (distances[i] == it->h) {
                        O.erase(it);
                        return *it;
                    }
                }
            }
        }
    }


