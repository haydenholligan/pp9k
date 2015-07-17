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
#include "view.h"

const int boardSize = 8;

class Game {
    //Board to hold the tiles, 8x8
    //white top left, alternate rest
    Tile **board;
    
    //Pointers to each player
    Player *p1;
    Player *p2;
    
    //holds pieces for each separate player
    std::vector<Piece> p1Pieces;
    std::vector<Piece> p2Pieces;
    
    View view;
    
public:
    Game(std::string s1, std::string s2);
    ~Game();
    void setup();
    string calcPosition(int x, int y);
    void endGame(Player *p);
    void move(Piece *pc, std::string p);
    void castle(Player *p);
    bool isCheck();
    bool isCheckmate();
    bool isStalemate();
    void upgrade(Piece);
    void updateBoard();
    void setPosition(Piece *pc, std::string s);
};

#endif
