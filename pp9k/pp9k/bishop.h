#ifndef __pp9k__bishop__
#define __pp9k__bishop__
#include <string>
#include "piece.h"

class Bishop: public Piece {
public:
    Bishop(int x, int y, std::string pos, char colour);
    //s is the position (ex. e5)
    std::string getName();
    bool isValidMove(std::string pos);
    bool isBlockedPath(std::string pos);
    bool move(std::string pos);
};

#endif
