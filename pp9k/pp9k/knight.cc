#include "knight.h"

Knight::Knight(int x, int y, std::string position, char colour): Piece(x, y, position, colour), name("knight") {}

bool Knight::isKnightMove(std::string pos){
	if(g->getTileAt(pos)->getPieceAt() != NULL) {
		if(g->getTileAt(string pos)->getPieceAt->getColour() == this->getColour()) return 1; // something about a null pointer}
	if(pieces blocking path) return 1; // something about a null pointer loop pieces
	
	return 0;
}

bool Knight::isValidMove(std::string pos) {
        
	if(pos == this->position) return 0;
	if(allied spot) return 0; // something about a null pointer
	if(pieces blocking path) return 0; // something about a null pointer
	if((pos[0] > 104 || pos[0] < 97 )||(pos[1] > '8' || pos[1] < '1')) return 0;
	if(!isKnightMove(pos)) return 0;
	return 1;
}