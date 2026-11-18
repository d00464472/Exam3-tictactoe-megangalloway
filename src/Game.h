#ifndef GAME_H
#define GAME_H

#include "Board.h"

class Game {
private:
    Board m_board;
    char m_currentPlayer;

    void switchPlayer();

public:
    Game();

    void play();
};

#endif
