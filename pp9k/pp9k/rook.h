#ifndef __pp9k__rook__
#define __pp9k__rook__
#include <string>
#include "piece.h"

class Rook: public Piece {
    int x, y;
    char colour;
    std::string name, position;
    bool hasMoved;
public:
    Rook(int x, int y, std::string pos, char colour);
    //s is the position (ex. e5)
    std::string getName();
    bool isValidMove(std::string pos);
    bool isBlockedPath(std::string pos);
    bool isRookMove(std::string pos);
    bool getHasMoved();
    void setHasMoved(bool b);
    bool move(std::string pos);
};

#endif
