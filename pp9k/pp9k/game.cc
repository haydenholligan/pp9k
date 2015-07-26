#include "game.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include "view.h"
#include "textView.h"
//#include <graphicsView.h>

using namespace std;

extern int numWhiteWin;
extern int numBlackWins;
extern int turn;

Game::Game(): board(NULL), p1Pieces(0), p2Pieces(0) {
    cout << "Calling game constructor" << endl;
    view = new textView;
}


Game::~Game() {
    cout << "Calling game destructor" << endl;
    
    for (int i = 0; i < boardSize; i++) {
        delete [] board[i];
    }
    
    delete [] board;
    delete p1;
    delete p2;
    nump1Pieces = 0;
    nump2Pieces = 0;
}

string Game::calcPosition(int x, int y) {
    char c = x + 97;
    string s = "";
    //add c to the beginning of the string
    s = s + c;
    //this just flips j so instead of 0, you get 8, or instead of 1 you get 7, etc. due to the layout of a chessboard
    int i1 = 8 - y;
    s = s + to_string(i1);
    return s;
}

void Game::addPiece(char p, string pos) {
    char xx = pos[0];
    char yy = pos[1];
    int x = xx - 97;
    int y = 7 - (yy - 49);
    string s = calcPosition(x, y);
    switch(p) {
        case 'r':
            p2Pieces.push_back(*(new Rook(x, y, pos, 'b')));
            board[y][x].setPiece(&((p1Pieces.at(nump2Pieces))));
            nump2Pieces++;
            break;
            
        case 'n':
            p2Pieces.push_back(*(new Knight(x, y, calcPosition(x, y), 'b')));
            board[y][x].setPiece(&((p1Pieces.at(nump2Pieces))));
            nump2Pieces++;
            break;
            
        case 'b':
            p2Pieces.push_back(*(new Bishop(x, y, calcPosition(x, y), 'b')));
            board[y][x].setPiece(&((p1Pieces.at(nump2Pieces))));
            nump2Pieces++;
            break;
            
        case 'q':
            p2Pieces.push_back(*(new Queen(x, y, calcPosition(x, y), 'b')));
            board[y][x].setPiece(&((p1Pieces.at(nump2Pieces))));
            nump2Pieces++;
            break;
            
        case 'k':
            p2Pieces.push_back(*(new King(x, y, calcPosition(x, y), 'b')));
            board[y][x].setPiece(&((p1Pieces.at(nump2Pieces))));
            nump2Pieces++;
            break;
            
        case 'p':
            p2Pieces.push_back(*(new Pawn(x, y, calcPosition(x, y), 'b')));
            board[y][x].setPiece(&((p1Pieces.at(nump2Pieces))));
            nump2Pieces++;
            break;
            
        case 'R':
            p1Pieces.push_back(*(new Rook(x, y, calcPosition(x, y), 'w')));
            board[y][x].setPiece(&((p1Pieces.at(nump1Pieces))));
            nump1Pieces++;
            break;
            
        case 'N':
            p1Pieces.push_back(*(new Knight(x, y, calcPosition(x, y), 'w')));
            board[y][x].setPiece(&((p1Pieces.at(nump1Pieces))));
            nump1Pieces++;
            break;
            
        case 'B':
            p1Pieces.push_back(*(new Bishop(x, y, calcPosition(x, y), 'w')));
            board[y][x].setPiece(&((p1Pieces.at(nump1Pieces))));
            nump1Pieces++;
            break;
            
        case 'Q':
            p1Pieces.push_back(*(new Queen(x, y, calcPosition(x, y), 'w')));
            board[y][x].setPiece(&((p1Pieces.at(nump1Pieces))));
            nump1Pieces++;
            break;
            
        case 'K':
            p1Pieces.push_back(*(new King(x, y, calcPosition(x, y), 'w')));
            board[y][x].setPiece(&((p1Pieces.at(nump1Pieces))));
            nump1Pieces++;
            break;
            
        case 'P':
            p1Pieces.push_back(*(new Pawn(x, y, calcPosition(x, y), 'w')));
            board[y][x].setPiece(&((p1Pieces.at(nump1Pieces))));
            nump1Pieces++;
            break;
            
        default:
            cout << "Not a valid piece!" << endl;
            break;
    }
    //old position doesn't change, new position gets piece p
    updateBoard("0", s, p);
}

void Game::removePiece(string pos) {
    char xx = pos[0];
    char yy = pos[1];
    int x = xx - 97;
    int y = 7 - (yy - 49);
    if (board[y][x].getPiece() == NULL) {
        cout << "No piece to delete, taking no action" << endl;
        return;
    }
    else {
        
        string tmpName = board[y][x].getPiece()->getName();
        char tmpColour = board[y][x].getPiece()->getColour();

        for (int i = 0; i < max(p1Pieces.size(), p2Pieces.size()); i++) {
            if (p1Pieces.at(i).getName() == tmpName && p1Pieces.at(i).getColour() == tmpColour) {
                cout << "Found the piece, deleting from board" << endl;
                //might need to change formula for begin + i
                p1Pieces.erase(p1Pieces.begin() + i);
                board[y][x].setPiece(NULL);
                updateBoard(pos, "0", 'x');
            }
            
            else if (p1Pieces.at(i).getName() == tmpName && p1Pieces.at(i).getColour() == tmpColour) {
                cout << "Found the piece, deleting from board" << endl;
                p2Pieces.erase(p1Pieces.begin() + i);
                board[y][x].setPiece(NULL);
                updateBoard(pos, "0", 'x');
            }
        }
    }
}


void Game::move(string oldPos, string newPos, char up) {
    
    //get x, y coordinates
    char xx = oldPos[0];
    char yy = oldPos[1];
    int x = xx - 97;
    int y = 7 - (yy - 49);
    
    board[y][x].getPiece()->move(newPos);
    if (up != 'a') {
        upgrade(board[y][x].getPiece(), up);
    }
    //check for check, checkmate, stalemate, upgrade
    updateBoard(oldPos, newPos, up);
}

void Game::castle(Player *p) {
    //all if, no else if
    //return; ends the function, void so don't return anything
    if (king moved) {
        std::cout << "The king has already moved, cannot castle!" << endl;
        return;
	}
    if (rook moved) {
        std::cout << "The rook has already moved, cannot castle!" << endl;
        return;
    }
    
    if (pieces between) {
        std::cout << "There are pieces inbetween, cannot castle!" << endl;
        return;
	}
    
    if (this->isCheck()) {
        std::cout << "You are in check, cannot castle!" << endl;
        return;
	}
    
    if (any spots it passes can be attacked) {
        std::cout << "Can't move through possible attacked spaces, cannot castle!" << endl;
        return;
	}
    
    if (would be in check after move) {
        std::cout << "You would be in check, cannot castle!" << endl;

        return;
	}
    
    else {
        std::cout << "Castling!" << endl;

        //move
	}
}

char Game::getPieceAt(string pos) {
    //if no piece, char is = 'U'
    char xx = pos[0];
    char yy = pos[1];
    int x = xx - 97;
    int y = 7 - (yy - 49);
    string s = board[y][x].getPiece()->getName();
    char colour = board[y][x].getPiece()->getColour();
    if (colour == 'w') {
        if (s == "knight") {
            return 'N';
        }
        if (s == "king") {
            return 'K';
        }
        else {
            return toupper(s[0]);
        }
    }
    
    else if (colour == 'b') {
        if (s == "knight") {
            return 'n';
        }
        if (s == "king") {
            return 'k';
        }
        else {
            return tolower(s[0]);
        }
    }
    return 'A'; // bad if A
}

Player *Game::getPlayer(int pNum) {
    if (pNum == 1) {
        return p1;
    }
    else
        return p2;
}

bool Game::isValidPosition(string pos) {
    char xx = pos[0];
    int x = xx - 97;
    int y = 0;
    string s = pos.substr(1, (pos.length() - 1));
    stringstream ss(s);
    ss>>y;
    
    if (x < 0 || x > 7) {
        return 0;
    }
    if (y < 1 || y > 8) {
        return 0;
    }
    return 1;
}


bool Game::isCheck() {
    //should be simple to determine if a king is in check
    //every time a piece is moved, determine if any of the opponent's pieces
    //have legal moves to capture the king
    //if they do, it's check
    //this has to be checked before a move as well to make sure you
    //aren't placing your king in check
    
    //loop thru opponent's piece array, checking each person having a valid move to your King
    // if valid, return true
	int len;
	
<<<<<<< HEAD
	if(turn == 2) {len = p1pieces.size(); 
		string colour = "Black";
		for(int i = 0; i < p1pieces.size(); i++){
			if(p2pieces.at(i).getName() == 'king') 
				string pos = p2pieces.back().getPos();}
		for(int i = 0; i < len; i++){
			if(this->p1pieces.at(i).isValidMove(pos)){
=======
	if (last move is black) {
        len = p1pieces.size();
		string colour = "White";
		for (int i = 0; i < p1pieces.size(); i++) {
			if (p2pieces.at(i).getName() == 'king')
				string pos = p2pieces.back().getPos();
        }
        
		for (int i = 0; i < len; i++){
			if (this->p1pieces.at(i).isValidMove(pos)){
>>>>>>> origin/master
				cout << colour <<" is in check!" << endl;
				return 1;
            }
		}
	}
<<<<<<< HEAD
	else {len = p2pieces.size(); 
		string colour = "White";
=======
	else { //last move is white
        len = p2pieces.size();
		string colour = "Black";
>>>>>>> origin/master
		//gets your king's location
		for(int i = 0; i < p1pieces.size(); i++){
			if (p2pieces.at(i).getName() == 'king')
				string pos = p1pieces.back().getPos();
        }
		//checks if any of the opponents pieces can kill your king
		for (int i = 0; i < len; i++) {
			if (this->p2pieces.at(i).isValidMove(pos)){
				cout << colour <<" is in check!" << endl;
				return 1;
            }
		}
	}
}

   
    
    
    return 0;
}

bool Game::isCheckmate() {
    //ways to avoid checkmate:
    //1. capture the checking piece (doesn't work in double check)
    //2. move a piece inbetween the king and threatening piece
    //3. king moves out of check
    //if none of these are possible, it is checkmate or stalemate
    cout << "Checkmate! White wins!" << endl;
    cout << "Checkmate! Black wins!" << endl;
    
    return 0;
}

bool Game::isStalemate() {
    //If any player ever has no legal moves available, but is not
    //in check, it is known as stalemate,and the game is a draw.
    //taken from the assignment, this is all we need to do for isStalemate
    
    //loop through each piece, and if any possible move for that piece is invalid
    //and not check, then it's stalemate.
    
    cout << "Stalemate!" << endl;
    return 0;
}

void Game::upgrade(Piece *p, char piece) {
    int iter = 0;
	int x = p->getX();
	int y = p->getY();
	string pos = p->getPos();
	char c = p->getColour();
    
    switch (piece) {
        case 'Q':
            board[y][x].setPiece(new Queen(x, y, pos, c));
            break;
            
        case 'R':
            board[y][x].setPiece(new Rook(x, y, pos, c));
            break;
            
        case 'N':
            board[y][x].setPiece(new Knight(x, y, pos, c));
            break;
            
        case 'B':
            board[y][x].setPiece(new Bishop(x, y, pos, c));
            break;
            
        default:
            cout << "invalid character for upgrade" << endl;
            break;
    }
    
    string tmpName = board[y][x].getPiece()->getName();
    char tmpColour = board[y][x].getPiece()->getColour();
    
    //Find iterator spot
    for (int i = 0; i < max(p1Pieces.size(), p2Pieces.size()); i++) {
        if ((p1Pieces.at(i).getName() == tmpName) && (p1Pieces.at(i).getColour() == tmpColour)) {
            iter = i;
            p1Pieces.erase(p1Pieces.begin() + iter);
            p1Pieces.insert(p1Pieces.begin() + iter, *board[y][x].getPiece());
        }
        
        else if ((p2Pieces.at(i).getName() == tmpName) && (p2Pieces.at(i).getColour() == tmpColour)) {
            iter = i;
            p2Pieces.erase(p2Pieces.begin() + iter);
            p2Pieces.insert(p2Pieces.begin() + iter, *board[y][x].getPiece());
        }
    }
    updateBoard("0", pos, 'x');
}

Tile * Game::getTileAt(string pos) {
    char xx = pos[0];
    char yy = pos[1];
    int x = xx - 97;
    int y = 7 - (yy - 49);
    return &board[y][x];
}


void Game::updateBoard(std::string oldPos, std::string newPos, char c) {
    view->updateBoard(oldPos, newPos, c);
}

void Game::setPosition(Piece *pc, string s) {
    
}

//Set up the board
void Game::setup(string s1, string s2) {
    
    //initialize players
    if (s1 == "human")
        p1 = new Human(1);
    
    else if (s1 == "computer[1]")
        p1 = new Computer(1, 1);
    
    else if (s1 == "computer[2]")
        p1 = new Computer(2, 1);
    
    else if (s1 == "computer[3]")
        p1 = new Computer(3, 1);
    
    else if (s1 == "computer[4]")
        p1 = new Computer(4, 1);
    
    else
        cout << "invalid input" << endl;
    
    if (s2 == "human")
        p2 = new Human(1);
    
    else if (s2 == "computer[1]")
        p1 = new Computer(1, 1);
    
    else if (s2 == "computer[2]")
        p2 = new Computer(2, 1);
    
    else if (s2 == "computer[3]")
        p2 = new Computer(3, 1);
    
    else if (s2 == "computer[4]")
        p2 = new Computer(4, 1);
    
    else
        cout << "invalid input" << endl;
    
    
    //Initialize memory for the tiles
    board = new Tile*[boardSize];
    for (int i = 0; i < boardSize; i++) {
        board[i] = new Tile[boardSize];
    }
    
    //Initialize the pieces for player 1
    p2Pieces.push_back(*(new Rook(0, 0, calcPosition(0, 0), 'b')));
    p2Pieces.push_back(*(new Rook(7, 0,calcPosition(7, 0), 'b')));
    p2Pieces.push_back(*(new Knight(1, 0,calcPosition(1, 0), 'b')));
    p2Pieces.push_back(*(new Knight(6, 0,calcPosition(6, 0), 'b')));
    p2Pieces.push_back(*(new Bishop(2, 0,calcPosition(2, 0), 'b')));
    p2Pieces.push_back(*(new Bishop(5, 0,calcPosition(5, 0), 'b')));
    p2Pieces.push_back(*(new Queen(3, 0,calcPosition(3, 0), 'b')));
    p2Pieces.push_back(*(new King(4, 0,calcPosition(4, 0), 'b')));
    nump2Pieces += 8;
    
    //Initialize the pieces for player 2
    p1Pieces.push_back(*(new Rook(0, 7,calcPosition(0, 7), 'w')));
    p1Pieces.push_back(*(new Rook(7, 7,calcPosition(7, 7), 'w')));
    p1Pieces.push_back(*(new Knight(1, 7,calcPosition(1, 7), 'w')));
    p1Pieces.push_back(*(new Knight(6, 7,calcPosition(6, 7), 'w')));
    p1Pieces.push_back(*(new Bishop(2, 7,calcPosition(2, 7), 'w')));
    p1Pieces.push_back(*(new Bishop(5, 7,calcPosition(5, 7), 'w')));
    p1Pieces.push_back(*(new Queen(3, 7,calcPosition(3, 7), 'w')));
    p1Pieces.push_back(*(new King(4, 7,calcPosition(4, 7), 'w')));
    nump1Pieces += 8;
    
    //Initialize the pawns for both players
    for (int i = 0; i < boardSize; i++) {
        p2Pieces.push_back(*(new Pawn(i, 0,calcPosition(i, 0), 'b')));
        p1Pieces.push_back(*(new Pawn(i, 6,calcPosition(i, 6), 'w')));
        nump1Pieces++;
        nump2Pieces++;
    }
    
    //Initialize tile information
    
    //First row and last row
    for (int i = 0; i < boardSize; i++) {
        
        //Set x, y, position and piece for row 1
        string position = calcPosition(i, 0);
        board[0][i].setX(i);
        board[0][i].setY(0);
        board[0][i].setPos(position);
        board[0][i].setPiece(&((p2Pieces.at(i))));
        
        //Set x, y, position and piece for row 2
        position = calcPosition(i, 1);
        board[1][i].setX(i);
        board[1][i].setY(1);
        board[1][i].setPos(position);
        board[1][i].setPiece(&((p2Pieces.at(i+8))));
        
        
        //Set x, y, position and piece for row 7
        position = calcPosition(i, 7);
        board[7][i].setX(i);
        board[7][i].setY(7);
        board[7][i].setPos(position);
        board[7][i].setPiece(&((p1Pieces.at(i))));
        
        //Set x, y, position and piece for row 6
        position = calcPosition(i, 6);
        board[6][i].setX(i);
        board[6][i].setY(6);
        board[6][i].setPos(position);
        board[6][i].setPiece(&((p1Pieces.at(i+8))));
    }
    
    //Initialize empty cells
    for (int i = 2; i < 6; i++) {
        for (int j = 2; j < 6; j++) {
            string position = calcPosition(j, i);
            board[i][j].setX(j);
            board[i][j].setY(i);
            board[i][j].setPos(position);
            board[i][j].setPiece(NULL);
        }
    }
}

void Game::setup(char setupArr[9][8], bool isEmpty) {
    p1 = new Human(1);
    p2 = new Human(1);
    
    board = new Tile*[boardSize];
    for (int i = 0; i < boardSize; i++) {
        board[i] = new Tile[boardSize];
    }
    
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            string position = calcPosition(j, i);
            board[i][j].setX(j);
            board[i][j].setY(i);
            board[i][j].setPos(position);
            
            if (setupArr[i][j] == '_') {
                //blank space
                board[i][j].setPiece(NULL);
            }
            if (!(isEmpty)) {
                switch (setupArr[i][j]) {
                    case 'r':
                        p2Pieces.push_back(*(new Rook(j, i, calcPosition(j, i), 'b')));
                        board[i][j].setPiece(&((p1Pieces.at(nump2Pieces))));
                        nump2Pieces++;
                        break;
                        
                    case 'n':
                        p2Pieces.push_back(*(new Knight(j, i,calcPosition(j, i), 'b')));
                        board[i][j].setPiece(&((p1Pieces.at(nump2Pieces))));
                        nump2Pieces++;
                        break;
                        
                    case 'b':
                        p2Pieces.push_back(*(new Bishop(j, i,calcPosition(j, i), 'b')));
                        board[i][j].setPiece(&((p1Pieces.at(nump2Pieces))));
                        nump2Pieces++;
                        break;
                        
                    case 'q':
                        p2Pieces.push_back(*(new Queen(j, i,calcPosition(j, i), 'b')));
                        board[i][j].setPiece(&((p1Pieces.at(nump2Pieces))));
                        nump2Pieces++;
                        break;
                        
                    case 'k':
                        p2Pieces.push_back(*(new King(j, i,calcPosition(j, i), 'b')));
                        board[i][j].setPiece(&((p1Pieces.at(nump2Pieces))));
                        nump2Pieces++;
                        break;
                        
                    case 'p':
                        p2Pieces.push_back(*(new Pawn(j, i,calcPosition(j, i), 'b')));
                        board[i][j].setPiece(&((p1Pieces.at(nump2Pieces))));
                        nump2Pieces++;
                        break;
                        
                    case 'R':
                        p1Pieces.push_back(*(new Rook(j, i,calcPosition(j, i), 'w')));
                        board[i][j].setPiece(&((p1Pieces.at(nump1Pieces))));
                        nump1Pieces++;
                        break;
                        
                    case 'N':
                        p1Pieces.push_back(*(new Knight(j, i,calcPosition(j, i), 'w')));
                        board[i][j].setPiece(&((p1Pieces.at(nump1Pieces))));
                        nump1Pieces++;
                        break;
                        
                    case 'B':
                        p1Pieces.push_back(*(new Bishop(j, i,calcPosition(j, i), 'w')));
                        board[i][j].setPiece(&((p1Pieces.at(nump1Pieces))));
                        nump1Pieces++;
                        break;
                        
                    case 'Q':
                        p1Pieces.push_back(*(new Queen(j, i,calcPosition(j, i), 'w')));
                        board[i][j].setPiece(&((p1Pieces.at(nump1Pieces))));
                        nump1Pieces++;
                        break;
                        
                    case 'K':
                        p1Pieces.push_back(*(new King(j, i,calcPosition(j, i), 'w')));
                        board[i][j].setPiece(&((p1Pieces.at(nump1Pieces))));
                        nump1Pieces++;
                        break;
                        
                    case 'P':
                        p1Pieces.push_back(*(new Pawn(j, i,calcPosition(j, i), 'w')));
                        board[i][j].setPiece(&((p1Pieces.at(nump1Pieces))));
                        nump1Pieces++;
                        break;
                        
                    default:
                        break;
                }
            }
        }
    }
    
    if (!(isEmpty)) {
        //Initialize the pieces for player 1
        p2Pieces.push_back(*(new Rook(0, 0, calcPosition(0, 0), 'b')));
        p2Pieces.push_back(*(new Rook(7, 0,calcPosition(7, 0), 'b')));
        p2Pieces.push_back(*(new Knight(1, 0,calcPosition(1, 0), 'b')));
        p2Pieces.push_back(*(new Knight(6, 0,calcPosition(6, 0), 'b')));
        p2Pieces.push_back(*(new Bishop(2, 0,calcPosition(2, 0), 'b')));
        p2Pieces.push_back(*(new Bishop(5, 0,calcPosition(5, 0), 'b')));
        p2Pieces.push_back(*(new Queen(3, 0,calcPosition(3, 0), 'b')));
        p2Pieces.push_back(*(new King(4, 0,calcPosition(4, 0), 'b')));
        
        //Initialize the pieces for player 2
        p1Pieces.push_back(*(new Rook(0, 7,calcPosition(0, 7), 'w')));
        p1Pieces.push_back(*(new Rook(7, 7,calcPosition(7, 7), 'w')));
        p1Pieces.push_back(*(new Knight(1, 7,calcPosition(1, 7), 'w')));
        p1Pieces.push_back(*(new Knight(6, 7,calcPosition(6, 7), 'w')));
        p1Pieces.push_back(*(new Bishop(2, 7,calcPosition(2, 7), 'w')));
        p1Pieces.push_back(*(new Bishop(5, 7,calcPosition(5, 7), 'w')));
        p1Pieces.push_back(*(new Queen(3, 7,calcPosition(3, 7), 'w')));
        p1Pieces.push_back(*(new King(4, 7,calcPosition(4, 7), 'w')));
        
        //Initialize the pawns for both players
        for (int i = 0; i < boardSize; i++) {
            p2Pieces.push_back(*(new Pawn(i, 0,calcPosition(i, 0), 'b')));
            p1Pieces.push_back(*(new Pawn(i, 6,calcPosition(i, 6), 'w')));
        }
    }
    
    if (isEmpty) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                string position = calcPosition(j, i);
                board[i][j].setX(j);
                board[i][j].setY(i);
                board[i][j].setPos(position);
                board[i][j].setPiece(NULL);
            }
        }
    }
    //Initialize tile information
    
    else if (!isEmpty) {
        //First row and last row
        for (int i = 0; i < boardSize; i++) {
            
            //Set x, y, position and piece for row 1
            string position = calcPosition(i, 0);
            board[0][i].setX(i);
            board[0][i].setY(0);
            board[0][i].setPos(position);
            board[0][i].setPiece(&((p2Pieces.at(i))));
            
            //Set x, y, position and piece for row 2
            position = calcPosition(i, 1);
            board[1][i].setX(i);
            board[1][i].setY(1);
            board[1][i].setPos(position);
            board[1][i].setPiece(&((p2Pieces.at(i+8))));
            
            
            //Set x, y, position and piece for row 7
            position = calcPosition(i, 7);
            board[7][i].setX(i);
            board[7][i].setY(7);
            board[7][i].setPos(position);
            board[7][i].setPiece(&((p1Pieces.at(i))));
            
            //Set x, y, position and piece for row 6
            position = calcPosition(i, 6);
            board[6][i].setX(i);
            board[6][i].setY(6);
            board[6][i].setPos(position);
            board[6][i].setPiece(&((p1Pieces.at(i+8))));
        }
        
        //Initialize empty cells
        for (int i = 2; i < 6; i++) {
            for (int j = 2; j < 6; j++) {
                string position = calcPosition(j, i);
                board[i][j].setX(j);
                board[i][j].setY(i);
                board[i][j].setPos(position);
                board[i][j].setPiece(NULL);
            }
        }
    }
}


