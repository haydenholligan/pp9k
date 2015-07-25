#ifndef __pp9k__piece__
#define __pp9k__piece__

#include <string>

class Game;
//abstract class
class Piece {
private:
    int x,y;
    char colour;
    std::string name, position;
protected:
    Game *g;
public:
    Piece(int x, int y, std::string position, char colour);
    virtual int getX();
    virtual int getY();
    virtual std::string getPos();
    virtual std::string getName();
    virtual void setPos(std::string pos);
    virtual bool move(std::string pos);
    void setColour(char c);
    char getColour();
    std::string intPosToStr(int x,int y);
    //For isValidMove, make sure it accounts for movements as well as check/checkmate
    virtual bool isValidMove(std::string pos) = 0;
    Game * getGame();
    void setGame(Game * g);
    void stringSetPos(std::string pos);
};

#endif 