#ifndef __pp9k__human__
#define __pp9k__human__

#include "game.h"
#include "player.h"

class Human: public Player {
    Game *game;
    int numWins;
public:
    Human();
    ~Human();
    void movePiece(Piece *p, std::string location);
};
#endif
