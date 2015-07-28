#include "queen.h"
#include "game.h"
#include <cstdlib>
#include <iostream>

extern int dbg;

Queen::Queen(int x, int y, std::string position, char colour): Piece(x, y, position, colour) {
    this->name = "queen";
}

bool Queen::isBlockedPath(std::string pos){
    
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
    
    if (startX != destX && startY != destY) {
        if (abs(startX-destX) != abs(startY-destY)) {
        std::cout << "Invalid queen move!" << std::endl;
        return 1;
        }
    }
    //moving vertical
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
    
    //moving horizontal
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

    if (dbg) std::cout << "Ending queen::isBlockedPath, returning 0" << std::endl;
    return 0;
}

bool Queen::move(std::string pos) {
    if(isValidMove(pos)) {
        setPos(pos);
        return true;
    }
    else {
        std::cout << "Invalid move, try again" << std::endl;
        return false;
        
    }
}

bool Queen::isValidMove(std::string pos) {
    if(g->getTileAt(pos)->getPiece() != NULL) {
        if(g->getTileAt(pos)->getPiece()->getColour() == this->getColour()) {
            std::cout << "Your piece is there!" << std::endl;
            return 1;
        }
    }
    if(pos == this->position) return 0;
    if(isBlockedPath(pos)) return 0; // something about a null pointer
    return 1;
}

