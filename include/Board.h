#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <fstream>

using namespace std;

class Board
{
    public:
        Board();
        virtual ~Board();
        double **G;

        void createBoard() {

            string nazwap="grid.txt";

            while(rows--) G[rows] = new double[wym1+1];

            std::ifstream plik(nazwap.c_str());

            for ( unsigned int i=1;i<wym2+1;i++)
              {
                for ( unsigned int j=1;j<wym1+1;j++)
                {
                     plik >> G[i][j];
                }
              }
            plik.close();
        }

        void writeBoard() {
            for(int i=1;i<wym2+1;i++)
            {
                for(int j=1;j<wym1+1;j++)
                    {
                        cout<<" "<<G[i][j];
                    }cout<<"\n";
                }
        }


    protected:
    private:
        int wym2;
        int wym1;
        int rows;



};

#endif // BOARD_H
