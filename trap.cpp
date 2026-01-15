#include "trap.h"

Trap::Trap() {
    xCoordinate = 0;
    yCoordinate = 0;
}

Trap::Trap(int x, int y) {
    xCoordinate = x;
    yCoordinate = y;
}

Trap::Trap(const Trap& t) {
    xCoordinate = t.xCoordinate;
    yCoordinate = t.yCoordinate;
}

Trap::~Trap() {
    // No dynamic memory to free
}

int Trap::getXCoordinate() {
    return xCoordinate;
}

int Trap::getYCoordinate() {
    return yCoordinate;
}

void Trap::setXCoordinate() {
    xCoordinate = 0;
}

void Trap::setYCoordinate() {
    yCoordinate = 0;
}

ostream& operator<<(ostream& out, const Trap& t) {
    out << "Trap at (" << t.xCoordinate << ", " << t.yCoordinate << ")";
    return out;
}
