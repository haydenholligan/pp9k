#ifndef __pp9k__player__
#define __pp9k__player__

#include "piece.h"

class Game;

class Player {
     Game *game;
    int playerNum;
public:
    Player(int playerNum);
    virtual ~Player();
    int getPlayerNum();
    void setPlayerNum(int num);
    void setGame(Game *Game);
};

#endif 