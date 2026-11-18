#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
private:
    std::vector<char> m_spaces;

public:
    Board();

    void display() const;
    bool makeMove(int position, char player);
    bool checkWinner(char player) const;
    bool isFull() const;
};

#endif
