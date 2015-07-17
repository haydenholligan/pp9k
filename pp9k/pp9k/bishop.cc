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
	this->position = pos;
    
    char xx = pos[0];
    char yy = pos[1];
    int tempx = xx - 97;
    int tempy = yy - 49;
	this->x = tempx;
	this->y = tempy;
	    
}

bool Bishop::isValidMove(std::string pos) {

    return 0;
}