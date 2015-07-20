#include "bishop.h"
#include <cmath>

Bishop::Bishop(int x, int y, std::string position, char colour): Piece(x, y, position, colour), name("bishop") {}

bool Bishop::isBishopMove(std::string pos){
	int curX = this->getX(); 
	int curY = this->getY();
	char xx = pos[0];
    	char yy = pos[1];
	int moveX = xx - 97;
    	int moveY = yy - 49;
	if(abs(xx - MoveX) == abs(yy - MoveY)) return 1;
	return 0;
}

bool Bishop::ifBlockedPath(std::string pos){
	
	if(allied spot) return 0; // something about a null pointer
	if(pieces blocking path) return 0; // something about a null pointer
}

bool Bishop::isValidMove(std::string pos) {
	
        if(pos == this->position) return 0;
	if(isBlockedPath(pos)) return 0;
	if((pos[0] > 104 || pos[0] < 97 )||(pos[1] > '8' || pos[1] < '1')) return 0;
	if(!isBishopMove(pos)) return 0;
	return 1;
}