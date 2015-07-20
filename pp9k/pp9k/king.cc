#include "king.h"

King::King(int x, int y, std::string position, char colour): Piece(x, y, position, colour), name("king") {}

bool King::isKingMove(std::string pos){

}

bool King::isValidMove(std::string pos) {
        
	if(pos == this->position) return 0;
	if(allied spot) return 0; // something about a null pointer
	if(pieces blocking path) return 0; // something about a null pointer
	if((pos[0] > 104 || pos[0] < 97 )||(pos[1] > '8' || pos[1] < '1')) return 0;
	if(!isKingMove(pos)) return 0;
	return 1;
}