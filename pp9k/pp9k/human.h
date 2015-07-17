#ifndef __pp9k__human__
#define __pp9k__human__

#include "game.h"
#include "player.h"

class Human: public Player {
    Game *game;
    
public:
    void movePiece(Piece *p, std::string location);
    void castle();
    void resign();
    void setGame(Game *g);
};
#endif
