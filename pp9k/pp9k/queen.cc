#include "queen.h"

Queen::Queen(int x, int y, std::string position): Piece(x, y, position), name("queen") {}

void Queen::move(std::string pos) {
    
}

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
    
}

bool Queen::isValidMove(std::string pos) {
    
    return 0;
}