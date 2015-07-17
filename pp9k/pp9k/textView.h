#ifndef __pp9k__textView__
#define __pp9k__textView__
#include "view.h"

//10 for line # and space beforehand
const int boardWidth = 10;
const int boardHeight = 8;

class textView: public View {
    //Might need to change from 8
    char board[boardHeight][boardWidth];
public:
    textView();
    void printBoard();
};

#endif
