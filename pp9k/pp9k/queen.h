#ifndef __pp9k__queen__
#define __pp9k__queen__
#include <string>
#include "piece.h"

class Queen: public Piece {
public:
    Queen(int x, int y, std::string pos, char colour);
    //s is the position (ex. e5)
    std::string getName();
    bool isValidMove(std::string pos);
    bool isBlockedPath(std::string pos);
    bool move(std::string pos);
};

#endif
