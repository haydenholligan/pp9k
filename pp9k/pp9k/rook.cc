#include "rook.h"
#include "game.h"

Rook::Rook(int x, int y, std::string position, char colour): Piece(x, y, position, colour), name("rook") {}

bool Rook::isRookMove(std::string pos){
    char xx = pos[0];
    char yy = pos[1];
    int moveX = xx - 97;
    int moveY = yy - 49;
    
    if ((((xx - moveX) != 0) && ((yy - moveY)== 0)) || (((xx - moveX) == 0) && ((yy - moveY)!= 0))) return 1;
    return 0;
}

bool Rook::isBlockedPath(std::string pos){
    
    if(g->getTileAt(pos)->getPiece() != NULL) {
        if(g->getTileAt(pos)->getPiece()->getColour() == this->getColour()) return 1;}
    
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
        
        else if(arr[0] > arrPos[0]){
            arr[1]--;
        }
        
        else {
            arr[1]++;
        }
        
    }//while
    
    return 0;
}

bool Rook::isValidMove(std::string pos) {
    
    if(pos == this->position) return 0;
    if(isBlockedPath(pos)) return 0; // something about a null pointer
    if((pos[0] > 104 || pos[0] < 97 )||(pos[1] > '8' || pos[1] < '1')) return 0;
    if(!isRookMove(pos)) return 0;
    return 1;
}