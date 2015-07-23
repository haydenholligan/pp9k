#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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

char setupArr[9][8];
bool isBoardSet = 0;
int numWhiteWins = 0;
int numBlackWins = 0;

bool isPieceMine(Game *g, string pos, int turn) {
    if (g->getPlayer(turn)->getPlayerNum() == 1 && (g->getPieceAt(pos) >= 65 && g->getPieceAt(pos) <= 90)) {
        return true;
    }
    
    if (g->getPlayer(turn)->getPlayerNum() == 2 && (g->getPieceAt(pos) >= 97 && g->getPieceAt(pos) <= 122)) {
        return true;
    }
    return false;
}

void outputFinalScore() {
    cout << "Final Score: " << endl;
    cout << "White: " << numWhiteWins << endl;
    cout << "Black: " << numBlackWins << endl;
}

int main(int argc, const char * argv[]) {
    bool playing = false;
    int turn = -1;
    //1 is player 1's turn(white), 2 is player 2's turn(black)
    //Take input
    string s;
    Game *g = NULL;
    if (argc > 2) // argc should be 2 for correct execution
        // We print argv[0] assuming it is the program name
        cout<<"usage: "<< argv[0] <<" <filename>\n";
    
    else if (argc == 2) {
        ifstream file (argv[1]);
        if (!file.is_open())
            cout<<"Could not open file\n";
        else {
            cout << "opening file" << endl;
            char c;
            int down = 0, across = 0;
            while (file.get (c)) {
                if (c == '\n')
                    continue;
                setupArr[down][across] = c;
                across++;
                if (across==8) {
                    down++;
                    across = 0;
                }
            }

        }
        
        g = new Game;
        g->setup(setupArr);
        isBoardSet = true;
        playing = true;
        if (setupArr[9][0] == 'W') {
            turn = 1;
        }
        else if (setupArr[9][0] == 'B') {
            turn = 2;
        }
    }
    
    while (cin >> s) {
        if (s == "game") {
            if (playing) {
                cout << "already playing a game!" << endl;
                continue;
            }
            turn = 1;
            playing = true;
            string s1, s2;
            cin >> s1;
            cin >> s2;
            //might need to be fixed
            if (!isBoardSet) {
                g = new Game;
                g->setup(s1, s2);
                isBoardSet = true;
            }
        }
        
        else if (s == "resign") {
            if (turn == 1) {
                cout << "Black wins!" << endl;
                numBlackWins++;
                delete g;
                isBoardSet = false;
                playing = false;
            }
            
            else if (turn == 2) {
                cout << "White wins!" << endl;
                numWhiteWins++;
                delete g;
                isBoardSet = false;
                playing = false;
            }
        }
        
        else if (s == "move") {
            std::string oldPos, newPos;
            char upgrade = 0;
            cin >> oldPos;
            cin >> newPos;
            //make sure the player is moving THEIR pieces
            if (isPieceMine(g, oldPos, turn)) {
                //check for another cin statement for upgrading
                //newPos will be a8, so newPos[1] is 8 (or 0)
                if ((turn == 1 && newPos[1] == 8) || (turn == 2 && newPos[1] == 0)) {
                    cin >> upgrade;
                }
                
                g->move(oldPos, newPos, upgrade);
                if (g->isCheck()) {
                    if (g->isCheckmate()) {
                        //if it's white's turn, white gets a point, else black gets a point
                        (turn == 1) ? numWhiteWins++ : numBlackWins++;
                        delete g;
                        isBoardSet = false;
                        playing = false;
                    }
                }
                
                switch (turn) {
                    case 1:
                        cout << "Black's turn!" << endl;
                        turn = 2;
                        break;
                    case 2:
                        cout << "White's turn!" << endl;
                        turn = 1;
                    default:
                        break;
                }
            }
            
            else {
                cout << "You can only move YOUR pieces!" << endl;
            }
        }
        
        //finish setup
        else if (s == "setup") {
            if (playing) {
                cout << "already playing a game!" << endl;
                continue;
            }
            playing = true;
            char emptyBoard[9][8];
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 8; j++) {
                        emptyBoard[i][j] = '_';
                }
            }
            
            //might need to fix
            g = new Game;
            g->setup(emptyBoard);
            isBoardSet = true;
            string next;
            while (cin >> next) {
                if (next == "+") {
                    char piece;
                    string newPos;
                    cin >> piece;
                    cin >> newPos;
                    if (!(g->isValidPosition(newPos))) {
                        cout << "invalid position" << endl;
                        continue;
                    }
                    cout << "adding piece" << endl;
                    g->addPiece(playing, newPos);
                }
                
                else if (next == "-") {
                    string tilePos;
                    cin >> tilePos;
                    if (!(g->isValidPosition(tilePos))) {
                        cout << "invalid position" << endl;
                        continue;
                    }
                    g->removePiece(tilePos);
                }
                
                else if (next == "=") {
                    int s;
                    cin >> s;
                    turn = s;
                    cout << "Player " << s << "'s turn" << endl;
                }
                
                else if (next == "done") {
                    cout << "exiting setup" << endl;
                    break;
                }
                
                else {
                    cout << "not valid setup input" << endl;
                    continue;
                }
            }
        }
        
        else {
            cout << "invalid input" << endl;
        }
        
    }
    outputFinalScore();
    delete g;
}
