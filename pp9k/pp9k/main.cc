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
            std::string oldPos, newPos, upgrade;
            cin >> oldPos;
            cin >> newPos;
            
        }
        
        else if (s == "setup") {
            
        }
        
        else {
            cout << "invalid input" << endl;
        }
        
        
    }
}
