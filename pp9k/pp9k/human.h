#ifndef __pp9k__human__
#define __pp9k__human__

#include "game.h"
#include "player.h"

class Human: public Player {
    int playerNumber;
    int numWins;
    Game *game;

public:
    Human(int playerNum);
    ~Human();
    void movePiece(Piece *p, std::string location);
};
#endif
