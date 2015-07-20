#include "knight.h"

Knight::Knight(int x, int y, std::string position, char colour): Piece(x, y, position, colour), name("knight") {}

bool Knight::isKnightMove(std::string pos){

}

bool Knight::isValidMove(std::string pos) {
        
	if(pos == this->position) return 0;
	if(allied spot) return 0; // something about a null pointer
	if(pieces blocking path) return 0; // something about a null pointer
	if((pos[0] > 104 || pos[0] < 97 )||(pos[1] > '8' || pos[1] < '1')) return 0;
	if(!isKnightMove(pos)) return 0;
	return 1;
}