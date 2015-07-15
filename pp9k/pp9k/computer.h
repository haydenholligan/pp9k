#ifndef __pp9k__computer__
#define __pp9k__computer__

#include "player.h"

class Computer: public Player {
    int level;
public:
    void movePiece(Piece, std::string);
    void castle();
    void resign();
    //void setGame(const &Game);
};


#endif
