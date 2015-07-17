#include "textView.h"

textView::textView() {
    
    for (int i = 0; i < boardHeight; i++) {
        board[i][0] = 'a';
        board[i][1] = ' ';
    }
    
    //Initialize blank spaces
    for (int i = 2; i < 6; i++) {
        for (int j = 2; j < 10; j++) {
            if ((i % 2 == 0) && (j % 2 == 0)) {
                board[i][j] = ' ';
            }
            else if ((i % 2 != 0) && (j % 2 != 0)) {
                board[i][j] = ' ';
            }
            
            else {
                board[i][j] = '-';
            }
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

