#ifndef __pp9k__king__
#define __pp9k__king__
#include <string>
#include "piece.h"

class King: public Piece {
    int x, y;
    char colour;
    std::string name, position;
public:
    King(int x, int y, std::string pos);
    //s is the position (ex. e5)
    bool move(std::string pos);
    int getX();
    int getY();
    std::string getPos();
    std::string getName();
    void setPos(std::string pos);
    bool isValidMove(std::string pos);
    void stringSetPos(std::string pos);
};

#endif
