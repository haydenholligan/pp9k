#ifndef __pp9k__piece__
#define __pp9k__piece__

#include <string>

//abstract class
class Piece {
private:
    int x,y;
    std::string name;
public:
    Piece(int x, int y, std::string name);
    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual std::string getPos() = 0;
    virtual std::string getName() = 0;
    virtual void setPos(std::string pos) = 0;
    virtual void move(std::string pos) = 0;
    virtual bool isValidMove(std::string pos) = 0;
};

#endif 