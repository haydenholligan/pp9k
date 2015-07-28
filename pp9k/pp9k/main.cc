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

bool dbg = true;

char setupArr[9][8];
bool isBoardSet = 0;
int numWhiteWins = 0;
int numBlackWins = 0;
int turn = -1;
//1 is player 1's turn(white), 2 is player 2's turn(black)

bool isPieceMine(Game *g, string pos, int turn) {
    if (dbg) {
        cout << "inside isPieceMine" << endl;
        cout << "g->getPlayer(turn)->getPlayerNum(): " << g->getPlayer(turn)->getPlayerNum() << endl;
        cout << "g->getPieceAt(" << pos << ") " << g->getPieceAt(pos) << endl << endl;
    }
    
    if (g->getPlayer(turn)->getPlayerNum() == 1 && (g->getPieceAt(pos) >= 65 && g->getPieceAt(pos) <= 90)) {
        if (dbg) cout << "Player 1 is valid" << endl;
        return true;
    }
    
    if (g->getPlayer(turn)->getPlayerNum() == 2 && (g->getPieceAt(pos) >= 97 && g->getPieceAt(pos) <= 122)) {
        if (dbg) cout << "Player 2 is valid" << endl;
        return true;
    }
    if (dbg) cout << "Not valid" << endl;
    return false;
}

void outputFinalScore() {
    cout << "Final Score: " << endl;
    cout << "White: " << numWhiteWins << endl;
    cout << "Black: " << numBlackWins << endl;
}

int main(int argc, const char * argv[]) {
    cout << "starting game" << endl;
    bool playing = false;
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
input:
    while (cin >> s) {
        if (s == "game") {
            if (playing) {
                cout << "already playing a game!" << endl;
                continue;
            }
	turn = 1;
		if (dbg) cout << "Turn: " << turn << endl;
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
            if (dbg) {
                cout << "moving, oldPos: " << oldPos << "    newPos: " << newPos << endl;
            }
            //make sure the player is moving THEIR pieces
            if (isPieceMine(g, oldPos, turn)) {
                //check for another cin statement for upgrading
                //newPos will be a8, so newPos[1] is 8 (or 0)
                if ((turn == 1 && newPos[1] == 8) || (turn == 2 && newPos[1] == 0)) {
                    cin >> upgrade;
                    if (!g->move(oldPos, newPos, upgrade)) {
                        cout << "Going to input" << endl;
                        goto input;
                    }
                }
                
                else {
                    if (dbg) cout << "main: before calling g->move" << endl;
                    if (!g->move(oldPos, newPos)) {
                        cout << "Going to input" << endl;
                        goto input;
                    }
                    
                    if (dbg) cout << "main: after calling g->move" << endl;

                }
                
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
