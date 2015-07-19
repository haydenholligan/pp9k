#include "queen.h"

Queen::Queen(int x, int y, std::string position, char colour): Piece(x, y, position, colour), name("queen") {}

int Queen::getX() {
    return this->x;
}

int Queen::getY() {
    return this->y;
}
std::string Queen::getPos() {
    return this->position;
}

std::string Queen::getName() {
    return this->name;
}

void Queen::setPos(std::string pos) {
    stringSetPos(pos);
}

bool Queen::isValidMove(std::string pos) {
    
    return 0;
}