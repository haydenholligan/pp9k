#include "rook.h"
#include "game.h"
#include <iostream>

extern int dbg;

Rook::Rook(int x, int y, std::string position, char colour): Piece(x, y, position, colour), hasMoved(0) {
    this->name = "rook";
}

bool Rook::isBlockedPath(std::string pos){
    if (dbg) std::cout << "Inside rook::isblockedPath" << std::endl;
    
    
    // putting current position and desired move into arrays of numbers to ease the comparison of them
    char xx = pos[0];
    char yy = pos[1];
    int destX = xx - 97;
    int destY = 7 - (yy - 49);
    
    int startX = this->getX();
    int startY = this->getY();
    
    if (dbg) {
        std::cout << "test" << std::endl;
        std::cout << "Start X, Y: " << startX << ", " << startY << std::endl;
        std::cout << "Dest X, Y: " << destX << ", " << destY << std::endl;
        
    }
    
    if (startX != destX && startY != destY) {
        std::cout << "Rook cannot move diagonal" << std::endl;
        return 1;
    }
    
    if (startX == destX) {
        if (startY < destY) {
            for (int i = startY; i < destY; i++) {
                if (g->getTileAt(intPosToStr(startX, i)) != NULL) {
                    if (dbg) std::cout << "Path is blocked" << std::endl;
                    return 1;
                }
            }
        }
        
        else if (startY > destY) {
            for (int i = startY; i < destY; i--) {
                if (g->getTileAt(intPosToStr(startX, i)) != NULL) {
                    if (dbg) std::cout << "Path is blocked" << std::endl;
                    return 1;
                }
            }
        }
    }
    
    else if (startY == destY) {
        if (startX < destX) {
            for (int i = startX; i < destX; i++) {
                if (g->getTileAt(intPosToStr(i, startY)) != NULL) {
                    if (dbg) std::cout << "Path is blocked" << std::endl;
                    return 1;
                }
            }
        }
        
        else if (startX > destX) {
            for (int i = startX; i < destX; i--) {
                if (g->getTileAt(intPosToStr(i, startY)) != NULL) {
                    if (dbg) std::cout << "Path is blocked" << std::endl;
                    return 1;
                }
            }
        }
    }
    
    std::cout << "end isBlockedPath, returning 0" << std::endl;
    return 0;
}

bool Rook::move(std::string pos) {
    if (isValidMove(pos)) {
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
