#ifndef __pp9k__player__
#define __pp9k__player__

#include "piece.h"


class Player {
    
public:
    virtual void movePiece(Piece, std::string) = 0;
    virtual void castle() = 0;
    virtual void resign() = 0;
    //virtual void setGame(const &Game) = 0;
};

#endif 