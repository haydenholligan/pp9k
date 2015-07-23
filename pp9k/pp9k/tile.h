#ifndef __pp9k__tile__
#define __pp9k__tile__

#include "piece.h"

#include <string>

class Tile {
    int x, y;
    std::string position;
    Piece *pieceOnTile;
public:
    Tile();
    ~Tile();
   // Tile(int x, int y, std::string pos, Piece *p);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    Piece *getPiece();
    std::string getPos();
    void setPos(std::string pos);
    void setPiece(Piece *p);
};

#endif
