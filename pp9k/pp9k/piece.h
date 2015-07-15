#ifndef __pp9k__piece__
#define __pp9k__piece__

#include <string>

//abstract class
class Piece {
public:
    //Might need constructor and/or destructor
    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual std::string getPos() = 0;
    virtual std::string getName() = 0;
    virtual void setPos(std::string pos) = 0;
    virtual void move(std::string pos) = 0;
};

#endif 