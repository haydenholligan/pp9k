#ifndef __pp9k__player__
#define __pp9k__player__

#include "piece.h"

class Game;

class Player {
    int numWins;
    Game *game;
public:
    Player();
    ~Player();
    //movePiece is virtual bc computer's will be different
    virtual void movePiece(Piece, std::string);
    //rest don't need to be virtual
    void castle();
    void resign();
    void addWin();
    void setGame(Game *Game);
};

#endif 