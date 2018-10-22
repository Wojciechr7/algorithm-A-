#include "../include/Board.h"

Board::Board()
{
    //ctor
    Board::wym1 = 20;
    Board::wym2 = 20;
    Board::rows = wym2+1;
    Board::G = new double*[rows];
    Board::createBoard();
}

Board::~Board()
{
    //dtor
}
