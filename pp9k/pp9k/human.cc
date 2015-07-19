#include "human.h"

Human::Human(int playerNum): Player(playerNum) {}

Human::~Human() {
    game = NULL;
}

void Human::movePiece(Piece *p, std::string location) {
    
}
