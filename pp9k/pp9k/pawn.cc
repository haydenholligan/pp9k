#include "pawn.h"
#include "game.h"
#include <cstdlib>

Pawn::Pawn(int x, int y, std::string position, char colour): Piece(x, y, position, colour), name("pawn") {}

bool Pawn::isPawnMove(std::string pos) {
	
	// ((this->getColour() == 'w' && moveY > yy) || (this->getColour() == 'b' && moveY < yy)) 
        // makes sure the pawns are going in the right direction

	int curY = this->getY();
    
	char xx = pos[0];
        char yy = pos[1];
    
	int moveX = xx - 97;
        int moveY = yy - 49;
	
	if(g->getTileAt(pos)->getPiece() != NULL) {
		if(g->getTileAt(pos)->getPiece()->getColour() == this->getColour()) return 0; // something about a null pointer}
	
	if (((abs(xx - moveX) == abs(yy - moveY)) == 1) &&
		((this->getColour() == 'w' && moveY > yy) || (this->getColour() == 'b' && moveY < yy)) &&
			((g->getTileAt(pos)->getPiece() != NULL) && 
				(g->getTileAt(pos)->getPiece()->getColour() != this->getColour()))) return 1; //attacking opponents diagonally 1 unit

	if ((abs(yy - moveY) == 1) &&
		((this->getColour() == 'w' && moveY > yy) || (this->getColour() == 'b' && moveY < yy)) &&
			((g->getTileAt(pos)->getPiece() == NULL))) return 1; //moving 1 unit forward
	
	//checks what colour and piece it is to verify its in its initial position
	if (((abs(yy - moveY) == 2)) &&
		((this->getColour() == 'w' && moveY > yy) || (this->getColour() == 'b' && moveY < yy)) &&
			((this->getColour() == 'w' && curY == 2) || (this->getColour() == 'b' && curY == 6)) &&
				((g->getTileAt(pos)->getPiece() == NULL))) return 1; //moving 2 units forward on first move
    }
	//en passant
	
	return 0;
}


bool Pawn::isValidMove(std::string pos) {
    
	if(pos == this->position) return 0;
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
