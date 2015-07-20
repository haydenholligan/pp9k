#include "knight.h"

Knight::Knight(int x, int y, std::string position, char colour): Piece(x, y, position, colour), name("knight") {}

bool Knight::isValidMove(std::string pos) {
        
	if(pos == this->position) return 0;
	if(allied spot) return 0;
	if(pieces blocking path) return 0;
	if((pos[0] > 104 || pos[0] < 97 )||(pos[1] > 8 || pos[1] < 1)) return 0;
	if(illegal piece move) return 0;
	return 1;
}