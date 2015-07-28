#include "king.h"
#include "game.h"
#include <cstdlib>
#include <iostream>

extern int dbg;

King::King(int x, int y, std::string position, char colour): Piece(x, y, position, colour), hasMoved(0) {
    this->name = "king";
}

bool King::isKingMove(std::string pos){
    
    char xx = pos[0];
    char yy = pos[1];
    int moveX = xx - 97;
    int moveY = 7 - (yy - 49);
    
    int startX = this->getX();
    int startY = this->getY();
    
    if ((abs(startX - moveX) > 1) || (abs(startY - moveY) > 1)) {
        if (dbg) std::cout << "king can't move more than 1 space" << std::endl;
        return 0;
    }
    
    if (g->getTileAt(pos)->getPiece() == NULL) return 1;
    
    return 0;
}


bool King::isValidMove(std::string pos) {
    if (dbg) std::cout << "inside king::isValidMove()" << std::endl;

    if(pos == this->position) return 0;
    if (dbg) std::cout << "after pos=this->pos" << std::endl;
    if(g->getTileAt(pos)->getPiece() != NULL) {
        if(g->getTileAt(pos)->getPiece()->getColour() == this->getColour()) return 0; // something about a null pointer}
    }
    if (dbg) std::cout << "after colour check" << std::endl;
    if (isKingMove(pos)) return 1;
    else return 0;
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
