#include "bishop.h"
#include "game.h"
#include <cstdlib>
#include <iostream>

extern int dbg;

Bishop::Bishop(int x, int y, std::string position, char colour): Piece(x, y, position, colour) {
    this->name = "bishop";
}


bool Bishop::isBlockedPath(std::string pos){
    if (dbg) std::cout << "Calling bishop::isBlockedPath" << std::endl;
    
    if(g->getTileAt(pos)->getPiece() != NULL) {
        if(g->getTileAt(pos)->getPiece()->getColour() == this->getColour()) return 1;}
    
    // putting current position and0 desired move into arrays of numbers to ease the comparison of them
    char xx = pos[0];
    char yy = pos[1];
    int destX = xx - 97;
    int destY = 7 - (yy - 49);
    
    int startX = this->getX();
    int startY = this->getY();
    
    if (dbg) {
        std::cout << "Start X, Y: " << startX << ", " << startY << std::endl;
        std::cout << "Dest X, Y: " << destX << ", " << destY << std::endl;
        
    }
    
    if(abs(startX-destX) != abs(startY-destY)) {
        std::cout << "Invalid position for bishop!" << std::endl;
        return 1;
    }
    
    //moving down-right
    if (startX < destX && startY < destY) {
        int i = startX;
        int j = startY;
        
        while (i < startX) {
            if (g->getTileAt(intPosToStr(i, j)) != NULL) {
                if (dbg) std::cout << "Path is blocked!" << std::endl;
                return 1;
            }
            i++;
            j++;
        }
    }
    
    //moving up-left
    else if (startX > destX && startY > destY) {
        int i = startX;
        int j = startY;
        
        while (i > startX) {
            if (g->getTileAt(intPosToStr(i, j)) != NULL) {
                if (dbg) std::cout << "Path is blocked!" << std::endl;
                return 1;
            }
            i--;
            j--;
        }
    }
    
    //moving down-left
    else if (startX > destX && startY < destY) {
        int i = startX;
        int j = startY;
        
        while (i > startX) {
            if (g->getTileAt(intPosToStr(i, j)) != NULL) {
                if (dbg) std::cout << "Path is blocked!" << std::endl;
                return 1;
            }
            i--;
            j++;
        }
    }
    //moving up-right
    else if (startX < destX && startY > destY) {
        int i = startX;
        int j = startY;
        
        while (i < startX) {
            if (g->getTileAt(intPosToStr(i, j)) != NULL) {
                if (dbg) std::cout << "Path is blocked!" << std::endl;
                return 1;
            }
            i++;
            j--;
        }
    }
    
    if (dbg) std::cout << "Ending ispathblocked, returning 0" << std::endl;
    return 0;
}

bool Bishop::move(std::string pos) {
    if(isValidMove(pos)) {
        setPos(pos);
        return true;
    }
    else {
        std::cout << "Invalid move, try again" << std::endl;
        return false;
        
    }
}

bool Bishop::isValidMove(std::string pos) {
    if (dbg) std::cout << "starting bishop::isValidMove" << std::endl;
    if(pos == this->position) return 0;
    if (dbg) std::cout << "after pos == this->pos" << std::endl;
    if(isBlockedPath(pos)) return 0;
    if (dbg) std::cout << "after isBlockedPath" << std::endl;
    return 1;
}

