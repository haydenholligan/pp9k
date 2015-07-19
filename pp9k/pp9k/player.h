#ifndef __pp9k__player__
#define __pp9k__player__

#include "piece.h"

class Game;

class Player {
    int playerNumber;
    int numWins;
    Game *game;
public:
    Player(int playerNum);
    ~Player();
    //movePiece is virtual bc computer's will be different
    virtual void movePiece(Piece, std::string);
    //rest don't need to be virtual
    int getPlayerNum();
    void setPlayerNum(int num);
    void castle();
    void resign();
    void addWin();
    void setGame(Game *Game);
};

#endif 