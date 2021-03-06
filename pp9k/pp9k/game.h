#ifndef __pp9k__game__
#define __pp9k__game__
#include <string>
#include <vector>

#include "player.h"
#include "human.h"
#include "computer.h"
#include "tile.h"
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "queen.h"
#include "king.h"

const int boardSize = 8;

class View;

class Game {
public:
    //Board to hold the tiles, 8x8
    //white top left, alternate rest
    Tile **board;
    //Pointers to each player
    Player *p1;
    Player *p2;
    
    //holds pieces for each separate player
    std::vector<Piece *> p1Pieces;
    std::vector<Piece *> p2Pieces;
    
    int nump1Pieces;
    int nump2Pieces;
    

   View *view;
    
    Game();
    ~Game();
    void setup(std::string s1, std::string s2);
    void setup(char setupArr[9][8], bool isEmpty = 0);
    void addPiece(char p, std::string pos);
    void removePiece(std::string pos);
    std::string calcPosition(int x, int y);
    bool move(std::string oldPos, std::string newPos, char up = 'a');
    void castle(std::string newPos, King *k, Rook *r);
    bool isCheck(std::string pos = "a0");
    Player *getPlayer(int pNum);
    bool isCheckmate();
    bool isStalemate();
    void setPlayer(std::string s1, std::string s2);
    char getPieceAt(std::string p);
    void upgrade(Piece *p, char piece);
    void updateBoard(std::string oldPos = "0", std::string newPos = "0", char c = 'a');
    bool isValidPosition(std::string pos);
    Tile *getTileAt(std::string pos);
    void setPosition(Piece *pc, std::string s);
};

#endif
