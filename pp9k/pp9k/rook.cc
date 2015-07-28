#include "rook.h"
#include "game.h"
#include <iostream>

extern int dbg;

Rook::Rook(int x, int y, std::string position, char colour): Piece(x, y, position, colour), hasMoved(0) {
    this->name = "rook";
}

bool Rook::isRookMove(std::string pos){
    char xx = pos[0];
    char yy = pos[1];
    int moveX = xx - 97;
    int moveY = yy - 49;
    
    if ((((xx - moveX) != 0) && ((yy - moveY)== 0)) || (((xx - moveX) == 0) && ((yy - moveY)!= 0))) return 1;
    return 0;
}

bool Rook::isBlockedPath(std::string pos){
    if (dbg) std::cout << "Inside rook::isblockedPath" << std::endl;
    
    // putting current position and desired move into arrays of numbers to ease the comparison of them
    char xx = pos[0];
    char yy = pos[1];
    int arrPos[2] = {xx - 97, 7 - (yy - 49)}; // pos as an array of num coordinates
    int arr[2] = {this->getX(), this->getY()}; //current location as an array of num coordinates
    
    //loops and checks if each tile between the current and the desired move is empty
    while(arr[0] != arrPos[0] || arr[1] != arrPos[1]){//not final position
        
        //if the tile we are looking at is not empty, the path is blocked and return TRUE
        if(g->getTileAt(intPosToStr(arr[0],arr[1]))->getPiece() != NULL) return 1; //if current tile being checked is non-NULL, return true
        
        //increments to next position we are checking between current and desired future spot, depending on where bishop is in relation to final spot
        if(arr[0] < arrPos[0]){
            arr[0]++;
        }
        
        else if (arr[0] > arrPos[0]){
            arr[0]--;
        }
        
        else if(arr[1] > arrPos[1]){
            arr[1]--;
        }
        
        else {
            arr[1]++;
        }
        
    }//while
    std::cout << "end isBlockedPath, returning 0" << std::endl;
    return 0;
}

bool Rook::move(std::string pos) {
    if(isValidMove(pos)) {
        setPos(pos);
        return true;
    }
    else {
        std::cout << "Invalid move, try again" << std::endl;
        return false;
        
    }
}


bool Rook::isValidMove(std::string pos) {
    if (dbg) std::cout << "Inside rook::isValidMove" << std::endl;
    
    if (g->getTileAt(pos)->getPiece() != NULL && g->getTileAt(pos)->getPiece()->getColour() == this->getColour()) { //check to make sure not attacking same colour
            return 0;
    }
    
    if (pos == this->position) return 0;
    if (isBlockedPath(pos)) return 0; // something about a null pointer
    
    return 1;
}


bool Rook::getHasMoved() {
    return hasMoved;
}

void Rook::setHasMoved(bool b) {
    hasMoved = b;
}
