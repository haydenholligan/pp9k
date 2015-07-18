#include "textView.h"
#include <iostream>

using namespace std;

textView::textView() {
    
    for (int i = 0; i < boardHeight; i++) {
        board[i][0] = 'a';
        board[i][1] = ' ';
    }
    
    //Initialize blank spaces
    for (int i = 2; i < 6; i++) {
        for (int j = 2; j < 10; j++) {
            board[i][j] = dashOrSpace(i, j);
        }
    }

    //Initialize top player's pieces
    board[0][2] = 'r';
    board[0][9] = 'r';
    board[0][3] = 'n';
    board[0][8] = 'n';
    board[0][4] = 'b';
    board[0][7] = 'b';
    board[0][5] = 'q';
    board[0][6] = 'k';
    
    //Initialize bottom player's pieces
    board[7][2] = 'R';
    board[7][9] = 'R';
    board[7][3] = 'N';
    board[7][8] = 'N';
    board[7][4] = 'B';
    board[7][7] = 'B';
    board[7][5] = 'Q';
    board[7][6] = 'K';
    
    //Initialize pawns
    for (int i = 2; i < 10; i++) {
        board[1][i] = 'p';
        board[6][i] = 'P';
    }
}

//Determine if dash or blank for chess board
char textView::dashOrSpace(int x, int y) {
    if ((x % 2 == 0) && (y % 2 == 0)) {
        return ' ';
    }
    
    else if ((x % 2 != 0) && (y % 2 != 0)) {
        return ' ';
    }
    
    else {
        return '-';
    }
}

void textView::updateBoard(string oldPos, string newPos, char newChar) {
    
}

void textView::setPos(string pos) {
    char xx = pos[0];
    char yy = pos[1];
    int tempx = xx - 97;
    int tempy = yy - 49;
    
}

void textView::setGame(Game *g) {
    game = g;
}

void textView::printBoard() {
    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << endl;
}





