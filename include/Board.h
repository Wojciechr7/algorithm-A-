#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <fstream>
#include "Robot.h"
#include <list>
#include "Step.h";


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
        }

        std::list<Step> findAvailableMoves(Robot r) {
            //cout << r.pos.x << r.pos.y << "pozycja robota" << endl;

            std::list<Step> moves;

            for (int i = 0; i < sizeof(dirX) / sizeof(int); i++) {
                int x, y;
                x = r.pos.x + dirX[i];
                y = r.pos.y + dirY[i];

                if (x >= 0 && x <= 19 && y >= 0 && y <= 19) {
                       if (G[x][y] == 0) {
                        //cout << x << " : " << y << endl;
                        moves.push_back(Step(x, y, r.pos.x, r.pos.y));
                       }
                }
            }

            return moves;
        }

        void signStep(Step s) {
            G[s.x][s.y] = 1;
        }


    protected:
    private:
        int wym2;
        int wym1;
        int rows;
        // N S W E
        int dirX[4]={0,0,-1,1};
        int dirY[4]={1,-1,0,0};



};

#endif // BOARD_H
