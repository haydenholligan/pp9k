#include "tile.h"

Tile::Tile(int x, int y, std::string pos): x(x), y(y), position(pos) {}

int Tile::getX() {
    return this->x;
}

int Tile::getY() {
    return this->y;
}

std::string Tile::getPos() {
    return this->position;
}

//sets the position as well as the x and y coordinates

void Tile::setPos(std::string) {
    
}