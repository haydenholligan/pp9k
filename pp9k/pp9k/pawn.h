#ifndef __pp9k__pawn__
#define __pp9k__pawn__
#include <string>
#include "piece.h"

class Pawn: public Piece {
public:
    Pawn(int x, int y, std::string pos, char colour);
    //s is the position (ex. e5)
    bool isValidMove(std::string pos);
    bool isPawnMove(std::string pos);
    bool move(std::string pos);
};

#endif
