#include "ai.h"

AI::AI() {
    name = "Opponent";
    xCoordinate = 0;
    yCoordinate = 0;
}

AI::AI(int x, int y, string opponentName) {
    xCoordinate = x;
    yCoordinate = y;
    name = opponentName;
}

AI::AI(const AI& a) {
    name = a.name;
    xCoordinate = a.xCoordinate;
    yCoordinate = a.yCoordinate;
}

AI::~AI() {
    // No resources to release
}

string AI::getName() {
    return name;
}

int AI::getXCoordinate() {
    return xCoordinate;
}

int AI::getYCoordinate() {
    return yCoordinate;
}

void AI::setName(string newName) {
    name = newName;
}

void AI::setXCoordinate(int x) {
    xCoordinate = x;
}

void AI::setYCoordinate(int y) {
    yCoordinate = y;
}

void AI::playerMove() {
    
}
