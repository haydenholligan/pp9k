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
   // Tile(int x, int y, std::string pos, Piece *p);
    int getX();
    int getY();
    Piece *getPiece();
    std::string getPos();
    void setPos(std::string);
    void setPiece(Piece *p);
};

#endif
