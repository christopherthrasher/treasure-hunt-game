#include "board.h"

Board::Board() {
    clearBoard();
}

Board::Board(int input[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            boardArr[i][j] = input[i][j];
        }
    }
}

int Board::getBoard(int x, int y) {
    if (checkBoundaries(x, y)) {
        return boardArr[x][y];
    }
    return -1;
}

void Board::setBoard(int x, int y, int value) {
    if (checkBoundaries(x, y)) {
        boardArr[x][y] = value; 
    }
}

bool Board::checkBoundaries(int x, int y) {
    return x >= 0 && x < 5 && y >= 0 && y < 5;
}

char Board::checkSpace(int x, int y) {
    if (!checkBoundaries(x, y)) return '?';

    int value = boardArr[x][y];
    switch (value) {
        case 0: return '.';
        case 1: return 'X';
        case 2: return 'T';
        case 3: return 'O';
        case 4: return 'P';
        default: return '?';
    }
}

void Board::displayBoard() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "[" << checkSpace(i, j) << "]";
        }
        cout << endl;
    }
}

void Board::clearBoard() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            boardArr[i][j] = 0;
        }
    }
    boardArr[0][0] = 4;
}

ostream& operator<<(ostream& out, const Board& b) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            char symbol;
            switch (b.boardArr[i][j]) {
                case 0: symbol = '.'; break;
                case 1: symbol = 'X'; break;
                case 2: symbol = 'T'; break;
                case 3: symbol = 'O'; break;
                case 4: symbol = 'P'; break;
                default: symbol = '?';
            }
            out << "[" << symbol << "]";
        }
        out << endl;
    }
    return out;
}
