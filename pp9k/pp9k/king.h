#ifndef __pp9k__king__
#define __pp9k__king__
#include <string>
#include "piece.h"

class King: public Piece {
    bool hasMoved;
public:
    King(int x, int y, std::string pos, char colour);
    //s is the position (ex. e5)
    std::string getName();
    bool isValidMove(std::string pos);
    bool isKingMove(std::string pos);
    bool getHasMoved();
    void setHasMoved(bool b);
    bool move(std::string pos);
};

#endif
