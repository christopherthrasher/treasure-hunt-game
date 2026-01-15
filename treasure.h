#ifndef TREASURE_H
#define TREASURE_H

#include <iostream>
using namespace std;

// Represents a treasure on the board.
class Treasure {
private:
    int xCoordinate;
    int yCoordinate;

public:
    Treasure();
    Treasure(int, int);
    Treasure(const Treasure&);
    ~Treasure();

    int getXCoordinate();
    int getYCoordinate();

    void setXCoordinate();
    void setYCoordinate();

    friend ostream& operator<<(ostream&, const Treasure&);
};

#endif
