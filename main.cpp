#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "board.h"
#include "trap.h"
#include "treasure.h"
#include "player.h"
#include "user.h"
#include "ai.h"
#include "helpers.h"

using namespace std;

int main() { 
    srand(time(NULL));

    bool playAgain = true;
    char playChoice;

    while (playAgain) {
        Board gameBoard;
        Board displayBoard;
        fillBoard(gameBoard);

        string playerName;
        cout << "Enter your name: ";
        cin >> playerName;

        User player(100, 0, playerName, 0, 0);
        AI opponent(4, 4, "Computer");
        
        displayBoard.clearBoard();
        
        cout << "\nGame Start!\n";
        bool gameRunning = true;

        while (gameRunning) {
            cout << "\nCurrent Player Status:\n" << player << endl;

            cout << "\nYour current view of the board:\n";
            displayBoard.displayBoard();

            int ox = opponent.getXCoordinate();
            int oy = opponent.getYCoordinate();


            opponentMove(gameBoard, ox, oy);
            opponent.setXCoordinate(ox);
            opponent.setYCoordinate(oy);
            
            int hp = player.getHealthPoints();
            int treasures = player.getNumTreasures();
            int px = player.getXCoordinate();
            int py = player.getYCoordinate();
            displayBoard.setBoard(px, py, 0);
            userMove(gameBoard, px, py, hp, treasures);
            player.setHealthPoints(hp);
            player.setNumTreasures(treasures);
            player.setXCoordinate(px);
            player.setYCoordinate(py);


            displayBoard.setBoard(px, py, 4);

            if (player.checkWin()) {
                cout << "\nCongratulations " << player.getName() << "! You collected all the treasures and won!\n";
                gameRunning = false;
            } else if (player.checkLose()) {
                cout << "\nSorry " << player.getName() << ", you've lost all your health. Game over.\n";
                gameRunning = false;
            }
        }
        gameBoard.setBoard(opponent.getXCoordinate(), opponent.getYCoordinate(), 3);
        cout << "\nFinal board state:\n";
        gameBoard.displayBoard();

        cout << "\nWould you like to play again? (y/n): ";
        cin >> playChoice;
        if (playChoice != 'y' && playChoice != 'Y') {
            playAgain = false;
        }
    }

    cout << "Thanks for playing!\n";
    return 0;
}
