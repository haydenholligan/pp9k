#include "king.h"

King::King(int x, int y, std::string position): Piece(x, y, position), name("king") {}

void King::move(std::string pos) {
    
}

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
    
}