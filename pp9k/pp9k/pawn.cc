#include "pawn.h"

Pawn::Pawn(int x, int y, std::string pos): x(x), y(y), position(pos), name("pawn") {}

void Pawn::move(std::string pos) {
    
}

int Pawn::getX() {
    return this->x;
}

int Pawn::getY() {
    return this->y;
}
std::string Pawn::getPos() {
    return this->position;
}

std::string Pawn::getName() {
    return this->name;
}

void Pawn::setPos(std::string pos) {
    
}