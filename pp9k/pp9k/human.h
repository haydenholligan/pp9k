#ifndef __pp9k__human__
#define __pp9k__human__

#include "player.h"

class Human: public Player {
    
public:
    void movePiece(Piece, std::string);
    void castle();
    void resign();
    //void setGame(const &Game);
};
#endif
