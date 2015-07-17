#include "pawn.h"

Pawn::Pawn(int x, int y, std::string position): Piece(x, y, position), name("pawn") {}

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

bool Pawn::isValidMove(std::string pos) {
    
    return 0;
}
