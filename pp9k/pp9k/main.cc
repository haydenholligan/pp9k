#include <iostream>
#include <string>

using namespace std;

#include "game.h"
#include "tile.h"
#include "player.h"
#include "human.h"
#include "computer.h"
#include "piece.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "queen.h"
#include "king.h"
#include "view.h"
#include "textView.h"
#include "graphicsView.h"

bool isPieceMine(Game *g, string pos, int turn) {
    if (g->getPlayer(turn)->getPlayerNum() == 1 && (g->getPieceAt(pos) >= 65 && g->getPieceAt(pos) <= 90)) {
        return true;
    }
    
    if (g->getPlayer(turn)->getPlayerNum() == 2 && (g->getPieceAt(pos) >= 97 && g->getPieceAt(pos) <= 122)) {
        return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    bool playing = false;
    int turn = -1;
    //1 is player 1's turn(white), 2 is player 2's turn(black)
    //Take input
    string s;
    Game g;
    while (cin >> s) {
        if (s == "game" && playing == false) {
            turn = 1;
            playing = true;
            string s1, s2;
            cin >> s1;
            cin >> s2;
            //might need to be fixed
            g.setup(s1, s2);
        }
        
        else if (s == "resign") {
            if (turn == 1) {
                g.endGame(2);
            }
            
            else if (turn == 2) {
                g.endGame(1);
            }
        }
        
        else if (s == "move") {
            std::string oldPos, newPos;
            char upgrade;
            cin >> oldPos;
            cin >> newPos;
            //make sure the player is moving THEIR pieces
            if (isPieceMine(&g, oldPos, turn)) {
                //check for another cin statement for upgrading
                //newPos will be a8, so newPos[1] is 8 (or 0)
                if ((turn == 1 && newPos[1] == 8) || (turn == 2 && newPos[1] == 0)) {
                    cin >> upgrade;
                    char xx = oldPos[0];
                    char yy = oldPos[1];
                    int x = xx - 97;
                    int y = yy - 49;
                    g.move(g.board[x][y].getPiece(), newPos);
                    if (g.isCheck()) {
                        if (g.isCheckmate()) {
                            g.endGame(turn);
                        }
                    }
                }
                
                switch (turn) {
                    case 1:
                        turn = 2;
                        break;
                    case 2:
                        turn = 1;
                    default:
                        break;
                }
            }
            
            else {
                cout << "You can only move YOUR pieces!" << endl;
            }
            
        }
        
        else if (s == "setup") {
            
        }
        
        else {
            cout << "invalid input" << endl;
        }
        
        
    }
}
