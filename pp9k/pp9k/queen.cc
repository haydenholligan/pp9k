#include "queen.h"

Queen::Queen(int x, int y, std::string pos): x(x), y(y), position(pos), name("queen") {}

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