#include "piece.h"

//might change position later to use setPos function
Piece::Piece(int x, int y, std::string position): x(x), y(y), position(position) {}

void Piece::stringSetPos(std::string pos){
	this->position = pos;
    
    	char xx = pos[0];
    	char yy = pos[1];
    	int tempx = xx - 97;
    	int tempy = yy - 49;
	this->x = tempx;
	this->y = tempy;
}

