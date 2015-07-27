#include "king.h"
#include "game.h"
#include <cstdlib>

King::King(int x, int y, std::string position, char colour): Piece(x, y, position, colour), name("king"), hasMoved(0) {}

bool King::isKingMove(std::string pos){
    
    char xx = pos[0];
    char yy = pos[1];
    int moveX = xx - 97;
    int moveY = yy - 49;
    
    if(g->getTileAt(pos)->getPiece() != NULL) {
        if(g->getTileAt(pos)->getPiece()->getColour() == this->getColour()) return 0; // something about a null pointer}

	if(g->isCheck(pos)) return 0; //if it puts the king in Check, move is invalid
	
        if (((abs(xx - moveX) == abs(yy - moveY)) == 1) ||
            ((((xx - moveX) == 1) && ((yy - moveY) == 0)) || ((((xx - moveX) == 0) && ((yy - moveY) == 1)) &&
            ((g->getTileAt(pos)->getPiece() != NULL) &&
             (g->getTileAt(pos)->getPiece()->getColour() != this->getColour()))))) return 1; //attacks
        
        if (((abs(xx - moveX) == abs(yy - moveY)) == 1) ||
            ((((((xx - moveX) == 1) && ((yy - moveY) == 0)) || (((xx - moveX) == 0) && ((yy - moveY) == 1)))) &&
            (g->getTileAt(pos)->getPiece() == NULL))) return 1; //non attacks
    }
    return 0;
}

    bool King::isValidMove(std::string pos) {
        
        if(pos == this->position) return 0;
        //if(allied spot) return 0; // something about a null pointer
        //if(pieces blocking path) return 0; // something about a null pointer
        if((pos[0] > 104 || pos[0] < 97 )||(pos[1] > '8' || pos[1] < '1')) return 0;
        if(!hasMoved) return 0;
        hasMoved = true;
        return 1;
    }


bool King::getHasMoved() {
    return hasMoved;
}

void King::setHasMoved(bool b) {
    hasMoved = b;
}
