#include "knight.h"
#include "game.h"

Knight::Knight(int x, int y, std::string position, char colour): Piece(x, y, position, colour), name("knight") {}

bool Knight::isBishopMove(std::string pos){
	int curX = this->getX(); 
	int curY = this->getY();
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


bool Knight::isValidMove(std::string pos) {
        
	if(pos == this->position) return 0;
	if(isBlockedPath(pos)) return 0; // something about a null pointer
	if((pos[0] > 104 || pos[0] < 97 )||(pos[1] > '8' || pos[1] < '1')) return 0;
	if(!isKnightMove(pos)) return 0;
	return 1;
}