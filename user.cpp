#include "user.h"

User::User() : Player() {}

User::User(int hp, int treasures, string playerName, int x, int y)
    : Player(hp, treasures, playerName, x, y) {}

User::User(const User& other) : Player(other) {}

User::~User() {}

int User::getHealthPoints() {
    return healthPoints;
}

int User::getNumTreasures() {
    return numTreasures;
}

string User::getName() {
    return name;
}

int User::getXCoordinate() {
    return xCoordinate;
}

int User::getYCoordinate() {
    return yCoordinate;
}

void User::setHealthPoints(int hp) {
    healthPoints = hp;
}

void User::setNumTreasures(int treasures) {
    numTreasures = treasures;
}

void User::setName(string newName) {
    name = newName;
}

void User::setXCoordinate(int x) {
    xCoordinate = x;
}

void User::setYCoordinate(int y) {
    yCoordinate = y;
}

void User::playerMove() {
    // Implementation can be filled in later or handled by helpers
}

int User::updateHealth(int n) {
    healthPoints -= n;
    if (healthPoints < 0) {
        healthPoints = 0;
    }
    return healthPoints;
}

int User::setTreasureCount(int n) {
    numTreasures += n;
    if (numTreasures > 3) {
        numTreasures = 3;
    }
    return numTreasures;
}

bool User::checkWin() {
    return numTreasures >= 3;
}

bool User::checkLose() {
    return healthPoints <= 0;
}

ostream& operator<<(ostream& out, const User& u) {
    out << "Name: " << u.name << " | Health: " << u.healthPoints
        << " | Treasures: " << u.numTreasures
        << " | Position: (" << u.yCoordinate+1 << "," << u.xCoordinate+1 << ")";
    return out;
}
