#include "tile.h"

Tile::Tile(): x(0), y(0), position("0"), pieceOnTile(NULL) {}

Tile::~Tile() {
    pieceOnTile = NULL;
}

//Tile::Tile(int x, int y, std::string pos, Piece *p): x(x), y(y), position(pos), pieceOnTile((p != NULL) ? p : NULL) {}

int Tile::getX() {
    return x;
}

int Tile::getY() {
    return y;
}

void setX(int x) {
    x = x;
}

void setY(int y) {
    y = y;
}

std::string Tile::getPos() {
    return position;
}

void Tile::setPiece(Piece *p) {
    pieceOnTile = p;
}

Piece *Tile::getPiece() {
    return pieceOnTile;
}

//sets the position as well as the x and y coordinates
void Tile::setPos(std::string pos) {
    position = pos;
    char xx = pos[0];
    char yy = pos[1];
    int x2 = xx - 97;
    int y2 = 7 - (yy - 49);
    x = x2;
    y = y2;
}