#ifndef __pp9k__game__
#define __pp9k__game__
#include <string>
#include "player.h"
#include "piece.h"
#include "tile.h"

class Game {
    Tile board[8][8];
    
    
public:
    Game();
    ~Game();
    void setup();
    void endGame(Player *p);
    void move(Piece *pc, std::string s);
    bool isCheck();
    bool isCheckmate();
    bool isStalemate();
    void upgrade(Piece);
    void updateBoard();
    void setPosition(Piece *pc, std::string s);
};

#endif
