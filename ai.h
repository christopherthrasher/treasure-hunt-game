#ifndef AI_H
#define AI_H

#include <iostream>
#include "helpers.h"
using namespace std;

// Class representing the computer controlled opponent with movement tracking.
class AI {
private:
    string name;
    int xCoordinate;
    int yCoordinate;

public:
    AI();
    AI(int, int, string);
    AI(const AI&);
    ~AI();

    string getName();
    int getXCoordinate();
    int getYCoordinate();

    void setName(string);
    void setXCoordinate(int);
    void setYCoordinate(int);

    void playerMove();
};

#endif
