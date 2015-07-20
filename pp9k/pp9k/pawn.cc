#include "pawn.h"

Pawn::Pawn(int x, int y, std::string position, char colour): Piece(x, y, position, colour), name("pawn") {}

bool Pawn::isPawnMove(std::string pos){

}

bool Pawn::isValidMove(std::string pos) {
    
	if(pos == this->position) return 0;
	if(allied spot) return 0; // something about a null pointer
	if(pieces blocking path) return 0; // something about a null pointer
	if((pos[0] > 104 || pos[0] < 97 )||(pos[1] > '8' || pos[1] < '1')) return 0;
	if(!isPawnMove(pos)) return 0;
	return 1;
   /*
     1. must change from current position
     2. can't move to allied piece's spot
     3. can't move through pieces (unless knight)
     4. can't put king in check or checkmate
     5. string pos must be a valid position on the board
     6. for pawn, check en passant and whether it can attack diag, or move 2 forward
     7. make sure move is legal for that piece
     8.
     */
    return 0;
}
