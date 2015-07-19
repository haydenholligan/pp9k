#ifndef __pp9k__computer__
#define __pp9k__computer__

#include "player.h"

class Computer: public Player {
    int playerNumber;
    int level;
    Game *game;
    int numWins;
public:
    Computer(int playerNum, int level);
    void movePiece(Piece, std::string);
    void castle();
};


#endif
