#include "pawn.h"

Pawn::Pawn(int x, int y, std::string position, char colour): Piece(x, y, position, colour), name("pawn") {}

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
    stringSetPos(pos);
}

bool Pawn::isValidMove(std::string pos) {
    
    return 0;
}
