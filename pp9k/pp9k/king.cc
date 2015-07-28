#include "king.h"
#include "game.h"
#include <cstdlib>
#include <iostream>

King::King(int x, int y, std::string position, char colour): Piece(x, y, position, colour), hasMoved(0) {
    this->name = "king";
}

bool King::isKingMove(std::string pos){
    
    char xx = pos[0];
    char yy = pos[1];
    int moveX = xx - 97;
    int moveY = yy - 49;
    
    if(g->getTileAt(pos)->getPiece() != NULL) {
        if(g->getTileAt(pos)->getPiece()->getColour() == this->getColour()) return 0; // something about a null pointer}
        
        
        if (((abs(xx - moveX) == abs(yy - moveY)) == 1) ||
            ((((xx - moveX) == 1) && ((yy - moveY) == 0)) || ((((xx - moveX) == 0) && ((yy - moveY) == 1)) &&
                                                              ((g->getTileAt(pos)->getPiece() != NULL) &&
                                                               (g->getTileAt(pos)->getPiece()->getColour() != this->getColour()))))) return 1; //attacks
        
        if (((abs(xx - moveX) == abs(yy - moveY)) == 1) ||
            ((((((xx - moveX) == 1) && ((yy - moveY) == 0)) || (((xx - moveX) == 0) && ((yy - moveY) == 1)))) &&
             (g->getTileAt(pos)->getPiece() == NULL))) return 1; //non attacks
    }
    return 0;
}


bool King::isValidMove(std::string pos) {
    if(pos == this->position) return 0;
    if (isKingMove(pos)) return 1;
    return 1;
}


bool King::move(std::string pos) {
    if(isValidMove(pos)) {
        setPos(pos);
        return true;
    }
    else {
        std::cout << "Invalid move, try again" << std::endl;
        return false;
        
    }
}

bool King::getHasMoved() {
    return hasMoved;
}

void King::setHasMoved(bool b) {
    hasMoved = b;
}
