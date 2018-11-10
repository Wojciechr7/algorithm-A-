#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <fstream>
#include <list>
#include "Step.h"
#include "Target.h"


class Board
{
    public:
        Board();
        virtual ~Board();
        double **G;

        void createBoard() {

            std::string nazwap="grid.txt";

            while(rows--) G[rows] = new double[wym1];

            std::ifstream plik(nazwap.c_str());

              for ( int i=wym2-1;i>-1;i--)
              {
                for ( int j=0;j<wym1;j++)
                {
                     plik >> G[j][i];
                }
              }
            plik.close();
        }

        void writeBoard() {
            for(int i=wym2-1;i>-1;i--)
            {
                for(int j=0;j<wym1;j++)
                    {
                        std::cout<<" "<<G[j][i];
                    }std::cout<<"\n";
            }
            clearBoard();
        }



        std::list<Step> findAvailableMoves(std::list<Step>& Z, Target& t, std::list<Step>& O) {

            std::list<Step> moves;

            for (unsigned int i = 0; i < sizeof(dirX) / sizeof(int); i++) {
                int x, y;
                x = Z.back().x + dirX[i];
                y = Z.back().y + dirY[i];

                if (x >= 0 && x <= 19 && y >= 0 && y <= 19) {
                       if (!foundInClosedList(x, y, Z) && G[x][y] == 0) {
                        Step newStep(x, y, Z.back());
                        newStep.calculateDistance(t);
                        if (foundShorterMove(newStep, O)) {
                            moves.push_back(newStep);
                        }
                       }
                }
            }

            return moves;
        }


        void signSteps(std::list<Step> route) {
            std::list <Step> :: iterator it;
            for(it = route.begin(); it != route.end(); ++it) {
                    G[it->x][it->y] = 3;
            }
        }


    protected:
    private:
        int wym2;
        int wym1;
        int rows;
        // N S W E
        int dirX[4] = {0, 0, -1, 1};
        int dirY[4] = {1, -1, 0, 0};

        bool foundInClosedList(int x, int y, std::list<Step>& Z) {
            std::list <Step> :: iterator it;
            for(it = Z.begin(); it != Z.end(); ++it) {
                    if (it->x == x && it->y == y) {
                        return true;
                    }
            }
            return false;
        }

        bool foundShorterMove(Step& newStep, std::list<Step>& O) {
            std::list <Step> :: iterator it;
            for(it = O.begin(); it != O.end(); ++it) {
                if(it->x == newStep.x && it->y == newStep.y) {
                    if (it->h >= newStep.h) {
                        return false;
                    }
                }
            }
            return true;
        }

        void clearBoard() {
            for(int i=0;i<wym2+1;i++)
            {delete[] G[i];}
            delete[] G;
        }



};

#endif // BOARD_H
