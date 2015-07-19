#ifndef __pp9k__queen__
#define __pp9k__queen__
#include <string>
#include "piece.h"

class Queen: public Piece {
    int x, y;
    char colour;
    std::string name, position;
public:
    Queen(int x, int y, std::string pos);
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
