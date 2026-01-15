#include "player.h"

Player::Player() {
    healthPoints = 100;
    numTreasures = 0;
    name = "";
    xCoordinate = 0;
    yCoordinate = 0;
}

Player::Player(int health, int treasures, string playerName, int x, int y) {
    healthPoints = health;
    numTreasures = treasures;
    name = playerName;
    xCoordinate = x;
    yCoordinate = y;
}

Player::Player(const Player& p) {
    healthPoints = p.healthPoints;
    numTreasures = p.numTreasures;
    name = p.name;
    xCoordinate = p.xCoordinate;
    yCoordinate = p.yCoordinate;
}

int Player::getHealthPoints() {
    return healthPoints;
}

int Player::getNumTreasures() {
    return numTreasures;
}

string Player::getName() {
    return name;
}

int Player::getXCoordinate() {
    return xCoordinate;
}

int Player::getYCoordinate() {
    return yCoordinate;
}

void Player::setHealthPoints(int hp) {
    healthPoints = hp;
}

void Player::setNumTreasures(int treasures) {
    numTreasures = treasures;
}

void Player::setName(string newName) {
    name = newName;
}

void Player::setXCoordinate(int x) {
    xCoordinate = x;
}

void Player::setYCoordinate(int y) {
    yCoordinate = y;
}

ostream& operator<<(ostream& out, const Player& p) {
    out << "Player: " << p.name << " | Health: " << p.healthPoints
        << " | Treasures: " << p.numTreasures
        << " | Position: (" << p.yCoordinate << ", " << p.xCoordinate << ")";
    return out;
}
