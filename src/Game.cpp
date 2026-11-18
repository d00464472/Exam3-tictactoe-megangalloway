#include "Game.h"
#include <iostream>

using namespace std;

// Constructor
Game::Game() {
    m_currentPlayer = 'X';
}

// Switch between players
void Game::switchPlayer() {
    if (m_currentPlayer == 'X') {
        m_currentPlayer = 'O';
    }
    else {
        m_currentPlayer = 'X';
    }
}

// Run the game

void Game::play() {
    int position;
    bool gameOver = false;

    cout << "Welcome to Tic-Tac-Toe!\n";

    while (!gameOver) {
        m_board.display();

        cout << "Player " << m_currentPlayer;
        cout << ", choose a position (1-9): ";
        cin >> position;

        // Check for non-numeric input
        if (cin.fail()) {
            cout << "Please enter a number between 1 and 9.\n";

            cin.clear();
            cin.ignore(10000, '\n');

            continue;
        }

        // Check if the move is valid
        if (!m_board.makeMove(position, m_currentPlayer)) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        // Check if the current player won
        if (m_board.checkWinner(m_currentPlayer)) {
            m_board.display();
            cout << "Player " << m_currentPlayer << " wins!\n";
            gameOver = true;
        }
        // Check for a tie
        else if (m_board.isFull()) {
            m_board.display();
            cout << "The game is a tie!\n";
            gameOver = true;
        }
        else {
            switchPlayer();
        }
    }
}

