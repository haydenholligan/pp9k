#ifndef __pp9k__textView__
#define __pp9k__textView__
#include "view.h"
#include "game.h"
#include "piece.h"

#include <string>


//10 for line # and space beforehand
const int boardWidth = 10;
const int boardHeight = 8;

class textView: public View {
    char board[boardHeight][boardWidth];
    Game *game;
public:
    textView();
    ~textView();
    void printBoard();
    void setGame(Game *g);
    void setPos(std::string pos, char c);
    char dashOrSpace(int x, int y);
    char dashOrSpace(std::string pos);
    char getCharAt(std::string pos);
    void updateBoard(std::string oldPos, std::string newPos, char c = 'a');
};

#endif
