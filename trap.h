#ifndef TRAP_H
#define TRAP_H

#include <iostream>
using namespace std;

// Represents a trap on the game board.
class Trap {
private:
    int xCoordinate;
    int yCoordinate;

public:
    Trap();

    Trap(int, int);

    Trap(const Trap&);

    ~Trap();

    int getXCoordinate();
    int getYCoordinate();

    void setXCoordinate();
    void setYCoordinate();

    friend ostream& operator<<(ostream&, const Trap&);
};

#endif
