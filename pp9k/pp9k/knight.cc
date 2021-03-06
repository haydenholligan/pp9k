#include "knight.h"
#include "game.h"
#include <cstdlib>
#include <iostream>

extern int dbg;

Knight::Knight(int x, int y, std::string position, char colour): Piece(x, y, position, colour) {
    this->name = "knight";
}

bool Knight::isKnightMove(std::string pos) {

	char xx = pos[0];
    char yy = pos[1];
    
	int destX = xx - 97;
    int destY = 7 - (yy - 49);
    
    int startX = this->getX();
    int startY = this->getY();
    
    if (dbg) {
        std::cout << "Start X, Y: " << startX << ", " << startY << std::endl;
        std::cout << "Dest X, Y: " << destX << ", " << destY << std::endl;
    }
    
    if (abs(startX - destX) == 1 && abs(startY - destY) == 2) {
        return 1;
    }
    
    if (abs(startX - destX) == 2 && abs(startY - destY) == 1) {
        return 1;
    }
    
	return 0;
}

bool Knight::isBlockedPath(std::string pos){
	
	if(g->getTileAt(pos)->getPiece() != NULL) {
		if(g->getTileAt(pos)->getPiece()->getColour() == this->getColour()) return 1;}
	return 0;
}

bool Knight::move(std::string pos) {
    if(isValidMove(pos)) {
        setPos(pos);
        return true;
    }
    else {
        std::cout << "Invalid move, try again" << std::endl;
        return false;
        
    }
}


bool Knight::isValidMove(std::string pos) {
        
	if(pos == this->position) return 0;
	if(isBlockedPath(pos)) return 0; // something about a null pointer
	if(!isKnightMove(pos)) return 0;
	return 1;
}
