#ifndef __pp9k__computer__
#define __pp9k__computer__

#include "player.h"

class Computer: public Player {
    int level;
public:
    Computer(int playerNum, int level);
    void movePiece();
};


#endif
