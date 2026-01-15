#include "treasure.h"

Treasure::Treasure() {
    xCoordinate = 0;
    yCoordinate = 0;
}

Treasure::Treasure(int x, int y) {
    xCoordinate = x;
    yCoordinate = y;
}

Treasure::Treasure(const Treasure& t) {
    xCoordinate = t.xCoordinate;
    yCoordinate = t.yCoordinate;
}

Treasure::~Treasure() {
    // No dynamic memory used
}

int Treasure::getXCoordinate() {
    return xCoordinate;
}

int Treasure::getYCoordinate() {
    return yCoordinate;
}

void Treasure::setXCoordinate() {
    xCoordinate = 0;
}

void Treasure::setYCoordinate() {
    yCoordinate = 0;
}

ostream& operator<<(ostream& out, const Treasure& t) {
    out << "Treasure at (" << t.xCoordinate << ", " << t.yCoordinate << ")";
    return out;
}
