#ifndef __pp9k__player__
#define __pp9k__player__

#include "piece.h"

class Game;

class Player {
protected:
     Game *game;
    int playerNum;
public:
    Player(int playerNum, Game *g);
    virtual ~Player();
    int getPlayerNum();
    void setPlayerNum(int num);
    void setGame(Game *Game);
};

#endif 
