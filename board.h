#ifndef BOARD_H
#define BOARD_H

#include <iostream>
using namespace std;

// Manages a 5x5 game grid with methods to access, modify, and display board contents.
class Board {
private:
    int boardArr[5][5];

public:
    Board();
    Board(int[5][5]);

    int getBoard(int, int);
    void setBoard(int, int, int);

    bool checkBoundaries(int, int);
    char checkSpace(int, int);

    void displayBoard();
    void clearBoard();

    friend ostream& operator<<(ostream&, const Board&);
};

#endif
