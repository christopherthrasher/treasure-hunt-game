#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "helpers.h"
#include "board.h"
#include "player.h"
#include "user.h"

#include "helpers.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

void fillBoard(Board& board) {
    board.clearBoard();
    int treasuresPlaced = 0;
    int trapsPlaced = 0;
    int opponentPlaced = 0;
    

    while (treasuresPlaced < 5) {
        int x = randomGenerator(5);
        int y = randomGenerator(5);

        if (board.getBoard(x, y) == 0 && (x != 0 || y != 0)) {
            board.setBoard(x, y, 2);

            bool safePath = false;
            if (board.checkBoundaries(x + 1, y) && board.getBoard(x + 1, y) != 1) {safePath = true;}
            if (board.checkBoundaries(x - 1, y) && board.getBoard(x - 1, y) != 1) {safePath = true;}
            if (board.checkBoundaries(x, y + 1) && board.getBoard(x, y + 1) != 1) {safePath = true;}
            if (board.checkBoundaries(x, y - 1) && board.getBoard(x, y - 1) != 1) {safePath = true;}

            if (safePath) {
                treasuresPlaced++;
            } else {
                board.setBoard(x, y, 0);
            }
        }
    }

    int numTraps = 5 + randomGenerator(3);
    while (trapsPlaced < numTraps) {
        int x = randomGenerator(5);
        int y = randomGenerator(5);
        if (board.getBoard(x, y) == 0 && (x != 0 || y != 0)) {
            board.setBoard(x, y, 1);
            trapsPlaced++;
        }
    }

    while (opponentPlaced < 1) {
        int x = randomGenerator(5);
        int y = randomGenerator(5);
        if (board.getBoard(x, y) == 0 && (x != 0 || y != 0)) {
            board.setBoard(x, y, 3);
            opponentPlaced++;
        }
    }
}


bool checkSpaceValid(Board& board, int x, int y) {
    if (!board.checkBoundaries(x, y)) {
        return false;
    }

    return board.getBoard(x, y) == 0;
}

int randomGenerator(int a) {
    return rand() % a;
}

int healthRemover(Board& board, int x, int y) {
    int space = board.getBoard(x, y);

    if (space == 1) {
        return 20;
    } else if (space == 3) {
        return 10;
    }

    return 0;
}

void opponentMove(Board& board, int& x, int& y) {
    board.setBoard(x, y, 0);

    int newX, newY, direction;
    bool samePos = 0;
    do {
        direction = randomGenerator(2);
        if(direction == 0){
        newX = x + positionVector(randomGenerator(2));
        newY = y;
       }else{
        newY = y + positionVector(randomGenerator(2));
        newX = x;
        }
        if(newX == x && newY == y){
            samePos = 1;
        }
    } while (
        !board.checkBoundaries(newX, newY) ||
        board.getBoard(newX, newY) == 1 ||
        board.getBoard(newX, newY) == 2 ||
        board.getBoard(newX, newY) == 3 ||
        samePos == 1 
    );

    x = newX;
    y = newY;
    board.setBoard(x, y, 3);
}

void userMove(Board& board, int& x, int& y, int& userHealth, int& userTreasures) {
    char move;
    cout << "Enter move (W/A/S/D): ";
    cin >> move;

    int newX = x, newY = y;

    switch (toupper(move)) {
        case 'W':
            newX = x - 1;
            break;
        case 'A':
            newY = y - 1;
            break;
        case 'S':
            newX = x + 1;
            break;
        case 'D':
            newY = y + 1;
            break;
        default:
            cout << "Invalid input. Try again.\n";
            return;
    }

    if (board.checkBoundaries(newX, newY)) {
        int space = board.getBoard(newX, newY);

        if (space == 1) { 
            cout << "You stepped on a trap! Health -20.\n";
            userHealth -= 20;
        } else if (space == 2) { 
            cout << "You found a treasure! Treasures +1.\n";
            userTreasures++;
        } else if (space == 3) {
            cout << "You encountered the opponent! Health -30.\n";
            userHealth -= 30;
        }
            board.setBoard(x, y, 0);
            x = newX;
            y = newY;
            board.setBoard(x, y, 4);
    }  else {
        cout << "Invalid move. Try again.\n";
    }
}

void removeObject(int x, int y, Board& gameBoard, Board& displayBoard) {
    gameBoard.setBoard(x, y, 0);
    displayBoard.setBoard(x, y, 0);
}
int positionVector(int a){
        switch (a) {
            case 0:
                return -1;
            case 1:
                return 1;
            default:
                return 0;
        }
}
