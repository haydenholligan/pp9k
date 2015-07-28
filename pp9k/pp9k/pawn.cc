#include "pawn.h"
#include "game.h"
#include <cstdlib>
#include <iostream>

extern bool dbg;

Pawn::Pawn(int x, int y, std::string position, char colour): Piece(x, y, position, colour)
{
    this->name = "pawn";
}

bool Pawn::isPawnMove(std::string pos) {
    if (dbg) std::cout << "inside pawn::isPawnMove" << std::endl;
    if (dbg) std::cout << "AAAA   inside pawn::isPawnMove, pos = " << pos << std::endl;
    
    // ((this->getColour() == 'w' && moveY > yy) || (this->getColour() == 'b' && moveY < yy))
    // makes sure the pawns are going in the right direction
    int curX = this->getX();
    int curY = this->getY();
    
    char xx = pos[0];
    char yy = pos[1];
    int moveX = xx - 97;
    int moveY = 7 - (yy - 49);
    
    if (dbg) std::cout << "moveX: " << moveX << "   moveY: " << moveY << std::endl;
    if (dbg) std::cout << "curX: " << curX << "   curY: " << curY << std::endl;
    if (dbg) std::cout << "inside pawn::isPawnMove, after inits" << std::endl;
    
    
    if (g->getTileAt(pos)->getPiece() != NULL && curX == moveX) {
        std::cout << "There is a piece in front of you, can't move there" << std::endl;
        return 0;
    }
    
    
    if (dbg) std::cout << "inside pawn::isPawnMove, after check1" << std::endl;
    
    
    if (g->getTileAt(pos)->getPiece() != NULL) { //check to make sure there is a piece
        if (g->getTileAt(pos)->getPiece()->getColour() != this->getColour()) { //check to make sure not attacking same colour
            if (abs(curX - moveX) == abs(curY - moveY) == 1) { //check to make sure attacking diagonal
                if (this->getColour() == 'w' && curY - moveY == 1) {
                    std::cout << "white can attack!" << std::endl;
                    return 1;
                }
                
                if (this->getColour() == 'b' && (curY - moveY == -1)) {
                    std::cout << "black can attack!" << std::endl;
                    return 1;
                }
            }
        }
    } //attacking diagonal
        
    if (dbg) std::cout << "inside pawn::isPawnMove, after check2" << std::endl;
    
    if (g->getTileAt(pos)->getPiece() == NULL) {
        std::cout << "getTileAt->getPiece is null" << std::endl;
        if (this->getColour() == 'w' && curY - moveY == 1) {
            std::cout << "white can move!" << std::endl;
            return 1;
        }
        
        if (this->getColour() == 'b' && (curY - moveY == -1)) {
            std::cout << "black can move!" << std::endl;

            return 1;
        }
    } //moving 1 unit
    
    if (dbg) std::cout << "inside pawn::isPawnMove, after check3" << std::endl;
    
    if (g->getTileAt(pos)->getPiece() == NULL) {
        if (dbg) std::cout << "inside pawn::isPawnMove, getPiece == NULL" << std::endl;
        if (this->getColour() == 'w' && moveY == 4 && curY == 6) {
            return 1;
        }
        
        if (this->getColour() == 'b' && moveY == 3 && curY == 1) {
            return 1;
        }
    } //moving 2 units forward on first move

    if (dbg) std::cout << "inside pawn::isPawnMove, after check4" << std::endl;
    
    //en passant
    
    return 0;
}

bool Pawn::move(std::string pos) {
    if (dbg) std::cout << "inside pawn::move" << std::endl;
    if(isValidMove(pos)) {
        if (dbg) std::cout << "inside pawn::move, after isValidMove" << std::endl;
        setPos(pos);
        if (dbg) std::cout << "inside pawn::move, after setPos" << std::endl;
        
        return true;
    }
    
    else {
        std::cout << "Invalid move, try again" << std::endl;
        return false;
        
    }
}

bool Pawn::isValidMove(std::string pos) {
    if (dbg) std::cout << "inside pawn::isValidMove" << std::endl;
    
    if(pos == this->position) return 0;
    if (dbg) std::cout << "inside pawn::isValidMove, after pos == this->position" << std::endl;
    if((pos[0] > 104 || pos[0] < 97 )||(pos[1] > '8' || pos[1] < '1')) return 0;
    if (dbg) std::cout << "inside pawn::isValidMove, after weird check" << std::endl;
    if(!isPawnMove(pos)) return 0;
    if (dbg) std::cout << "inside pawn::isValidMove, after isPawnMove" << std::endl;
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
}
