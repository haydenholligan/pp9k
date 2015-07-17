#include "human.h"

void Human::movePiece(Piece *p, std::string location) {
    
}

void Human::castle() {

}

void Human::resign() {
    game->endGame(this);
}

void Human::setGame(Game *g) {
    this->game = g;
}