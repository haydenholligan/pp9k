#include "computer.h"
#include <cstdlib>
#include "game.h"
#include <iostream>

Computer::Computer(int level, int playerNum, Game *g): Player(playerNum, g), level(level) {}

extern int turn;

bool Computer::movePiece() {
    if (level) {
        
    }
    std::cout << "not implemented" << std::endl;
    return 0;
}
