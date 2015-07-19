#include "bishop.h"

Bishop::Bishop(int x, int y, std::string position): Piece(x, y, position), name("bishop") {}

void Bishop::move(std::string pos) {
    
}

int Bishop::getX() {
    return this->x;
}

int Bishop::getY() {
    return this->y;
}
std::string Bishop::getPos() {
    return this->position;
}

std::string Bishop::getName() {
    return this->name;
}

void Bishop::setPos(std::string pos) {
	stringSetPos(pos);
}

bool Bishop::isValidMove(std::string pos) {

    return 0;
}