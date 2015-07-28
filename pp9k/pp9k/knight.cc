#include "knight.h"
#include "game.h"
#include <cstdlib>
#include <iostream>

Knight::Knight(int x, int y, std::string position, char colour): Piece(x, y, position, colour) {
    this->name = "knight";
}

bool Knight::isKnightMove(std::string pos) {

	char xx = pos[0];
    char yy = pos[1];
    
	int moveX = xx - 97;
    int moveY = yy - 49;
 
	if (abs(xx - moveX) + abs(yy - moveY) == 3) return 1;
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
	if((pos[0] > 104 || pos[0] < 97 )||(pos[1] > '8' || pos[1] < '1')) return 0;
	if(!isKnightMove(pos)) return 0;
	return 1;
}