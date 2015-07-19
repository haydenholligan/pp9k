#include "king.h"

King::King(int x, int y, std::string position, char colour): Piece(x, y, position, colour), name("king") {}

int King::getX() {
    return this->x;
}

int King::getY() {
    return this->y;
}
std::string King::getPos() {
    return this->position;
}

std::string King::getName() {
    return this->name;
}

void King::setPos(std::string pos) {
    stringSetPos(pos);
}

bool King::isValidMove(std::string pos) {
    
    return 0;
}