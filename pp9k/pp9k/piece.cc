#include "piece.h"
#include <iostream>
#include <sstream>

//might change position later to use setPos function
Piece::Piece(int x, int y, std::string position, char colour): x(x), y(y), position(position), colour(colour), g(NULL) {}


Piece::~Piece() {
    g = NULL;
}

int Piece::getX() {
    return this->x;
}

int Piece::getY() {
    return this->y;
}
std::string Piece::getPos() {
    return this->position;
}

std::string Piece::getName() {
    return this->name;
}


void Piece::setPos(std::string pos) {
    this->position = pos;
    char xx = pos[0];
    char yy = pos[1];
    int x = xx - 97;
    int y = 7 - (yy - 49);
    this->x = x;
    this->y = y;
}

char Piece::getColour(){
    return this->colour;
}

void Piece::setColour(char c){
    this->colour = c;
    
}

std::string Piece::intPosToStr(int x, int y){
    std::stringstream ss;
    char c = x + 97;
    std::string s = "";
    //add c to the beginning of the string
    s = s + c;
    //this just flips j so instead of 0, you get 8, or instead of 1 you get 7, etc. due to the layout of a chessboard
    int i1 = 8 - y;
    ss << i1;
    s = s + ss.str();
    return s;
}

void Piece::setGame(Game * g){
    this->g = g;
}

Game * Piece::getGame(){
    return this->g;
}

