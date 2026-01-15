#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include "board.h"
using namespace std;

void fillBoard(Board&);

bool checkSpaceValid(Board&, int, int);

int randomGenerator(int);

int healthRemover(Board&, int, int);

void opponentMove(Board&, int&, int&);

template <typename T>
T getUserInput() {
    T input;
    cin >> input;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Try again: ";
        cin >> input;
    }
    return input;
}

void userMove(Board&, int&, int&, int&, int&);

void removeObject(int, int, Board&, Board&);

int positionVector(int a);

#endif
