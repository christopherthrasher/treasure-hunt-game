#ifndef USER_H
#define USER_H

#include <iostream>
#include "player.h"
using namespace std;

// Derived class representing the human player with game actions and status tracking.
class User : public Player {
public:
    User();

    User(int, int, string, int, int);

    User(const User&);

    ~User();

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

    void playerMove();
    int updateHealth(int);
    int setTreasureCount(int);
    bool checkWin();
    bool checkLose();

    friend ostream& operator<<(ostream&, const User&);
};

#endif
