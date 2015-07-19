#ifndef __pp9k__piece__
#define __pp9k__piece__

#include <string>

//abstract class
class Piece {
private:
    int x,y;
    char colour;
    std::string name, position;
public:
    Piece(int x, int y, std::string position, char colour);
    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual std::string getPos() = 0;
    virtual std::string getName() = 0;
    virtual void setPos(std::string pos) = 0;
    virtual bool move(std::string pos);
    void setColour(char c);
    char getColour();
    //For isValidMove, make sure it accounts for movements as well as check/checkmate
    virtual bool isValidMove(std::string pos) = 0;
    void stringSetPos(std::string pos);
};

#endif 