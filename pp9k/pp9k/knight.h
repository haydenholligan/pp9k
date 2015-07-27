#ifndef __pp9k__knight__
#define __pp9k__knight__
#include <string>
#include "piece.h"

class Knight: public Piece {
    int x, y;
    char colour;
    std::string name, position;
public:
    Knight(int x, int y, std::string pos, char colour);
    //s is the position (ex. e5)
    std::string getName();
    bool isValidMove(std::string pos);
    bool isBlockedPath(std::string pos);
    bool isKnightMove(std::string pos);
    bool move(std::string pos);
};

#endif
