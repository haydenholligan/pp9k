#ifndef __pp9k__computer__
#define __pp9k__computer__

#include "player.h"

class Computer: public Player {
    int level;
    Game *game;
    int numWins;
public:
    Computer(int level);
    void movePiece(Piece, std::string);
    void castle();
};


#endif
