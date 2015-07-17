#include "knight.h"

Knight::Knight(int x, int y, std::string position): Piece(x, y, position), name("knight") {}

void Knight::move(std::string pos) {
    
}

int Knight::getX() {
    return this->x;
}

int Knight::getY() {
    return this->y;
}
std::string Knight::getPos() {
    return this->position;
}

std::string Knight::getName() {
    return this->name;
}

void Knight::setPos(std::string pos) {
    
}

bool Knight::isValidMove(std::string pos) {
    
    return 0;
}