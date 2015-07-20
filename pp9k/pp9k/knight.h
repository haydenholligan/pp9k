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
    bool move(std::string pos);
    int getX();
    int getY();
    std::string getPos();
    std::string getName();
    void setPos(std::string pos);
    bool isValidMove(std::string pos);
    void stringSetPos(std::string pos);
    bool isKnightMove(std::string pos);
};

#endif
