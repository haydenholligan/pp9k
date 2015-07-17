#include "rook.h"

Rook::Rook(int x, int y, std::string position): Piece(x, y, position), name("rook") {}

void Rook::move(std::string pos) {
    
}

int Rook::getX() {
    return this->x;
}

int Rook::getY() {
    return this->y;
}
std::string Rook::getPos() {
    return this->position;
}

std::string Rook::getName() {
    return this->name;
}

void Rook::setPos(std::string pos) {
    
}

bool Rook::isValidMove(std::string pos) {
    
    return 0;
}