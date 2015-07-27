#ifndef __pp9k__piece__
#define __pp9k__piece__

#include <string>

class Game;
//abstract class
class Piece {
private:
    int x,y;
    std::string position, name;
    char colour;
protected:
    Game *g;
public:
    Piece(int x, int y, std::string position, char colour);
    int getX();
    int getY();
    std::string getPos();
    void setPos(std::string pos);
    std::string getName();
    virtual bool move(std::string pos) = 0;
    void setColour(char c);
    char getColour();
    std::string intPosToStr(int x,int y);
    //For isValidMove, make sure it accounts for movements as well as check/checkmate
    virtual bool isValidMove(std::string pos) = 0;
    Game * getGame();
    void setGame(Game * g);
};

#endif