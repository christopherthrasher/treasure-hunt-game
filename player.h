#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
using namespace std;

// Abstract base class representing a generic player with health, treasure count, name, and position.
class Player {
protected:
    int healthPoints;
    int numTreasures;
    string name;
    int xCoordinate;
    int yCoordinate;

public:
    Player();
    Player(int, int, string, int, int);
    Player(const Player&);
    virtual ~Player() {}

    int getHealthPoints();
    int getNumTreasures();
    string getName();
    int getXCoordinate();
    int getYCoordinate();

    void setHealthPoints(int);
    void setNumTreasures(int);
    void setName(string);
    void setXCoordinate(int);
    void setYCoordinate(int);

    virtual void playerMove() = 0;

    friend ostream& operator<<(ostream&, const Player&);
};

#endif
