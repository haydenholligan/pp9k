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
    //Take input
    string s;
    while (cin >> s) {
        if (s == "game" && playing == false) {
            playing = true;
            string s1, s2;
            cin >> s1;
            cin >> s2;
            Game g(s1, s2);
            g.setup();
        }
        
        
    }
}
