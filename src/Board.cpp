#include "Board.h"
#include <iostream>

using namespace std;

// Constructor: creates an empty board
Board::Board() {
    m_spaces = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
}

// Display the board
void Board::display() const {
    cout << "\n";

    for (int i = 0; i < 9; i++) {
        if (m_spaces[i] == ' ') {
            cout << i + 1;
        }
        else {
            cout << m_spaces[i];
        }

        if (i % 3 != 2) {
            cout << " | ";
        }
        else if (i != 8) {
            cout << "\n---------\n";
        }
    }

    cout << "\n\n";
}

// Place a player's marker
bool Board::makeMove(int position, char player) {
    if (position < 1 || position > 9) {
        return false;
    }

    if (m_spaces[position - 1] != ' ') {
        return false;
    }

    m_spaces[position - 1] = player;
    return true;
}

// Check if a player has won
bool Board::checkWinner(char player) const {
    // All possible winning combinations
    int wins[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    for (int i = 0; i < 8; i++) {
        if (m_spaces[wins[i][0]] == player &&
            m_spaces[wins[i][1]] == player &&
            m_spaces[wins[i][2]] == player) {
            return true;
        }
    }

    return false;
}

// Check if the board is full
bool Board::isFull() const {
    for (int i = 0; i < 9; i++) {
        if (m_spaces[i] == ' ') {
            return false;
        }
    }

    return true;
}
