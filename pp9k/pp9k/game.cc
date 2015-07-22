#include "game.h"
#include <iostream>
#include <sstream>
#include <algorithm>

Game::Game(): board(NULL), p1Pieces(0), p2Pieces(0) { }

Game::~Game() {
    
    for (int i = 0; i < boardSize; i++) {
        delete [] board[i];
    }
    
    delete [] board;
    delete p1;
    delete p2;
    nump1Pieces = 0;
    nump2Pieces = 0;
}

std::string Game::calcPosition(int x, int y) {
    //i is the column(a-h), j is the row(8-1)
    char c = y + 97;
    //new string
    std::string s = "";
    //add c to the beginning of the string
    s = s + c;
    //this just flips j so instead of 0, you get 8, or instead of 1 you get 7, etc. due to the layout of a chessboard
    int i1 = boardSize - x;
    s = s + std::to_string(i1);
    return s;
}

//should be done now
//might need to switch x and y in board[x][y]
void Game::addPiece(char p, std::string pos) {
    char xx = pos[0];
    char yy = pos[1];
    int x = xx - 97;
    int y = yy - 49;
    switch(p) {
        case 'r':
            p2Pieces.push_back(*(new Rook(x, y, pos, 'b')));
            board[x][y].setPiece(&((p1Pieces.at(nump2Pieces))));
            nump2Pieces++;
            break;
            
        case 'n':
            p2Pieces.push_back(*(new Knight(x, y, calcPosition(x, y), 'b')));
            board[x][y].setPiece(&((p1Pieces.at(nump2Pieces))));
            nump2Pieces++;
            break;
            
        case 'b':
            p2Pieces.push_back(*(new Bishop(x, y, calcPosition(x, y), 'b')));
            board[x][y].setPiece(&((p1Pieces.at(nump2Pieces))));
            nump2Pieces++;
            break;
            
        case 'q':
            p2Pieces.push_back(*(new Queen(x, y, calcPosition(x, y), 'b')));
            board[x][y].setPiece(&((p1Pieces.at(nump2Pieces))));
            nump2Pieces++;
            break;
            
        case 'k':
            p2Pieces.push_back(*(new King(x, y, calcPosition(x, y), 'b')));
            board[x][y].setPiece(&((p1Pieces.at(nump2Pieces))));
            nump2Pieces++;
            break;
            
        case 'p':
            p2Pieces.push_back(*(new Pawn(x, y, calcPosition(x, y), 'b')));
            board[x][y].setPiece(&((p1Pieces.at(nump2Pieces))));
            nump2Pieces++;
            break;
            
        case 'R':
            p1Pieces.push_back(*(new Rook(x, y, calcPosition(x, y), 'b')));
            board[x][y].setPiece(&((p1Pieces.at(nump1Pieces))));
            nump1Pieces++;
            break;
            
        case 'N':
            p1Pieces.push_back(*(new Knight(x, y, calcPosition(x, y), 'b')));
            board[x][y].setPiece(&((p1Pieces.at(nump1Pieces))));
            nump1Pieces++;
            break;
            
        case 'B':
            p1Pieces.push_back(*(new Bishop(x, y, calcPosition(x, y), 'b')));
            board[x][y].setPiece(&((p1Pieces.at(nump1Pieces))));
            nump1Pieces++;
            break;
            
        case 'Q':
            p1Pieces.push_back(*(new Queen(x, y, calcPosition(x, y), 'b')));
            board[x][y].setPiece(&((p1Pieces.at(nump1Pieces))));
            nump1Pieces++;
            break;
            
        case 'K':
            p1Pieces.push_back(*(new King(x, y, calcPosition(x, y), 'b')));
            board[x][y].setPiece(&((p1Pieces.at(nump1Pieces))));
            nump1Pieces++;
            break;
            
        case 'P':
            p1Pieces.push_back(*(new Pawn(x, y, calcPosition(x, y), 'b')));
            board[x][y].setPiece(&((p1Pieces.at(nump1Pieces))));
            nump1Pieces++;
            break;
            
        default:
            std::cout << "Not a valid piece!" << std::endl;
            break;
    }
}

void Game::removePiece(std::string pos) {
    char xx = pos[0];
    char yy = pos[1];
    int x = xx - 97;
    int y = yy - 49;
    if (board[x][y].getPiece() == NULL) {
        std::cout << "No piece to delete, taking no action" << std::endl;
        return;
    }
    else {
        std::string tmpName = board[x][y].getPiece()->getName();
        for (int i = 0; i < std::max(p1Pieces.size(), p2Pieces.size()); i++) {
            if (p1Pieces.at(i).getName() == tmpName) {
                std::cout << "Found the piece, deleting from board" << std::endl;
                //might need to change formula for begin + i
                p1Pieces.erase(p1Pieces.begin() + i);
                board[x][y].setPiece(NULL);
                //redisplay board here
            }
            
            if (p2Pieces.at(i).getName() == tmpName) {
                std::cout << "Found the piece, deleting from board" << std::endl;
                p2Pieces.erase(p1Pieces.begin() + i);
                board[x][y].setPiece(NULL);
                //redisplay board here
            }
        }
    }
}

void Game::endGame(int player) {
    if (player == 1) {
        p1->addWin();
    }
    
    else if (player == 2) {
        p2->addWin();
    }
}

void Game::move(std::string oldPos, std::string newPos, char up) {
    
    //get x, y coordinates
    char xx = oldPos[0];
    char yy = oldPos[1];
    int x = xx - 97;
    int y = yy - 49;
    
    board[x][y].getPiece()->move(newPos);
    if (up != 'a') {
        //piece is to be upgraded
        upgrade(board[x][y].getPiece(), up);
    }
    //check for check, checkmate, stalemate, upgrade
    updateBoard();
}

void Game::castle(Player *p) {
    
}

char Game::getPieceAt(std::string pos) {
    //if no piece, char is = 'U'
    char xx = pos[0];
    char yy = pos[1];
    int tempx = xx - 97;
    int tempy = yy - 49;
    std::string s = board[tempx][tempy].getPiece()->getName();
    char colour = board[tempx][tempy].getPiece()->getColour();
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

Player * Game::getPlayer(int pNum) {
    if (pNum == 1) {
        return p1;
    }
    else
        return p2;
}

bool Game::isValidPosition(std::string pos) {
    char xx = pos[0];
    int x = xx - 97;
    int y = 0;
    std::string s = pos.substr(1, (pos.length() - 1));
    std::stringstream ss(s);
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
    
    return 0;
}

bool Game::isCheckmate() {
    
    return 0;
}

bool Game::isStalemate() {
    
    return 0;
}

void Game::upgrade(Piece *p, char piece) {
    
}

Tile * Game::getTileAt(std::string pos) {
    char xx = pos[0];
    char yy = pos[1];
    int x = xx - 97;
    int y = yy - 49;
    return &board[x][y];
}


void Game::updateBoard() {
    
}

void Game::setPosition(Piece *pc, std::string s) {
    
}

//Set up the board
void Game::setup(std::string s1, std::string s2) {
    
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
        std::cout << "invalid input" << std::endl;
    
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
        std::cout << "invalid input" << std::endl;
    
    
    //Initialize memory for the tiles
    board = new Tile*[boardSize];
    for (int i = 0; i < boardSize; i++) {
        board[i] = new Tile[boardSize];
    }
    
    //Initialize the pieces for player 1
    p1Pieces.push_back(*(new Rook(0, 0, calcPosition(0, 0), 'b')));
    p1Pieces.push_back(*(new Rook(7, 0,calcPosition(7, 0), 'b')));
    p1Pieces.push_back(*(new Knight(1, 0,calcPosition(1, 0), 'b')));
    p1Pieces.push_back(*(new Knight(6, 0,calcPosition(6, 0), 'b')));
    p1Pieces.push_back(*(new Bishop(2, 0,calcPosition(2, 0), 'b')));
    p1Pieces.push_back(*(new Bishop(5, 0,calcPosition(5, 0), 'b')));
    p1Pieces.push_back(*(new Queen(3, 0,calcPosition(3, 0), 'b')));
    p1Pieces.push_back(*(new King(4, 0,calcPosition(4, 0), 'b')));
    nump1Pieces += 8;
    
    //Initialize the pieces for player 2
    p2Pieces.push_back(*(new Rook(0, 7,calcPosition(0, 7), 'w')));
    p2Pieces.push_back(*(new Rook(7, 7,calcPosition(7, 7), 'w')));
    p2Pieces.push_back(*(new Knight(1, 7,calcPosition(1, 7), 'w')));
    p2Pieces.push_back(*(new Knight(6, 7,calcPosition(6, 7), 'w')));
    p2Pieces.push_back(*(new Bishop(2, 7,calcPosition(2, 7), 'w')));
    p2Pieces.push_back(*(new Bishop(5, 7,calcPosition(5, 7), 'w')));
    p2Pieces.push_back(*(new Queen(3, 7,calcPosition(3, 7), 'w')));
    p2Pieces.push_back(*(new King(4, 7,calcPosition(4, 7), 'w')));
    nump2Pieces += 8;

    //Initialize the pawns for both players
    for (int i = 0; i < boardSize; i++) {
        p1Pieces.push_back(*(new Pawn(i, 0,calcPosition(i, 0), 'b')));
        p2Pieces.push_back(*(new Pawn(i, 6,calcPosition(i, 6), 'w')));
        nump1Pieces++;
        nump2Pieces++;
    }
    
    //Initialize tile information
    
    //First row and last row
    for (int i = 0; i < boardSize; i++) {
        
        //Set x, y, position and piece for row 1
        std::string position = calcPosition(i, 0);
        board[i][0].setX(i);
        board[i][0].setY(0);
        board[i][0].setPos(position);
        board[i][0].setPiece(&((p1Pieces.at(i))));
        
        //Set x, y, position and piece for row 2
        position = calcPosition(i, 1);
        board[i][1].setX(i);
        board[i][1].setY(1);
        board[i][1].setPos(position);
        board[i][1].setPiece(&((p1Pieces.at(i+8))));
        
        
        //Set x, y, position and piece for row 7
        position = calcPosition(i, 7);
        board[i][7].setX(i);
        board[i][7].setY(7);
        board[i][7].setPos(position);
        board[i][7].setPiece(&((p2Pieces.at(i))));
        
        //Set x, y, position and piece for row 6
        position = calcPosition(i, 6);
        board[i][6].setX(i);
        board[i][6].setY(6);
        board[i][6].setPos(position);
        board[i][6].setPiece(&((p2Pieces.at(i+8))));
    }
    
    //Initialize empty cells
    for (int i = 2; i < 6; i++) {
        for (int j = 2; j < 6; j++) {
            std::string position = calcPosition(i, j);
            board[i][j].setX(i);
            board[i][j].setY(j);
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
            std::string position = calcPosition(i, j);
            board[i][j].setX(i);
            board[i][j].setY(j);
            board[i][j].setPos(position);
            
            if (setupArr[i][j] == '_') {
                //blank space
                board[i][j].setPiece(NULL);
            }
            if (!(isEmpty)) {
                switch (setupArr[i][j]) {
                    case 'r':
                        p2Pieces.push_back(*(new Rook(i, j,calcPosition(i, j), 'b')));
                        board[i][j].setPiece(&((p1Pieces.at(nump2Pieces))));
                        nump2Pieces++;
                        break;
                        
                    case 'n':
                        p2Pieces.push_back(*(new Knight(i, j,calcPosition(i, j), 'b')));
                        board[i][j].setPiece(&((p1Pieces.at(nump2Pieces))));
                        nump2Pieces++;
                        break;
                        
                    case 'b':
                        p2Pieces.push_back(*(new Bishop(i, j,calcPosition(i, j), 'b')));
                        board[i][j].setPiece(&((p1Pieces.at(nump2Pieces))));
                        nump2Pieces++;
                        break;
                        
                    case 'q':
                        p2Pieces.push_back(*(new Queen(i, j,calcPosition(i, j), 'b')));
                        board[i][j].setPiece(&((p1Pieces.at(nump2Pieces))));
                        nump2Pieces++;
                        break;
                        
                    case 'k':
                        p2Pieces.push_back(*(new King(i, j,calcPosition(i, j), 'b')));
                        board[i][j].setPiece(&((p1Pieces.at(nump2Pieces))));
                        nump2Pieces++;
                        break;
                        
                    case 'p':
                        p2Pieces.push_back(*(new Pawn(i, j,calcPosition(i, j), 'b')));
                        board[i][j].setPiece(&((p1Pieces.at(nump2Pieces))));
                        nump2Pieces++;
                        break;
                        
                    case 'R':
                        p1Pieces.push_back(*(new Rook(i, j,calcPosition(i, j), 'b')));
                        board[i][j].setPiece(&((p1Pieces.at(nump1Pieces))));
                        nump1Pieces++;
                        break;
                        
                    case 'N':
                        p1Pieces.push_back(*(new Knight(i, j,calcPosition(i, j), 'b')));
                        board[i][j].setPiece(&((p1Pieces.at(nump1Pieces))));
                        nump1Pieces++;
                        break;
                        
                    case 'B':
                        p1Pieces.push_back(*(new Bishop(i, j,calcPosition(i, j), 'b')));
                        board[i][j].setPiece(&((p1Pieces.at(nump1Pieces))));
                        nump1Pieces++;
                        break;
                        
                    case 'Q':
                        p1Pieces.push_back(*(new Queen(i, j,calcPosition(i, j), 'b')));
                        board[i][j].setPiece(&((p1Pieces.at(nump1Pieces))));
                        nump1Pieces++;
                        break;
                        
                    case 'K':
                        p1Pieces.push_back(*(new King(i, j,calcPosition(i, j), 'b')));
                        board[i][j].setPiece(&((p1Pieces.at(nump1Pieces))));
                        nump1Pieces++;
                        break;
                        
                    case 'P':
                        p1Pieces.push_back(*(new Pawn(i, j,calcPosition(i, j), 'b')));
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
        p1Pieces.push_back(*(new Rook(0, 0, calcPosition(0, 0), 'b')));
        p1Pieces.push_back(*(new Rook(7, 0,calcPosition(7, 0), 'b')));
        p1Pieces.push_back(*(new Knight(1, 0,calcPosition(1, 0), 'b')));
        p1Pieces.push_back(*(new Knight(6, 0,calcPosition(6, 0), 'b')));
        p1Pieces.push_back(*(new Bishop(2, 0,calcPosition(2, 0), 'b')));
        p1Pieces.push_back(*(new Bishop(5, 0,calcPosition(5, 0), 'b')));
        p1Pieces.push_back(*(new Queen(3, 0,calcPosition(3, 0), 'b')));
        p1Pieces.push_back(*(new King(4, 0,calcPosition(4, 0), 'b')));
        
        //Initialize the pieces for player 2
        p2Pieces.push_back(*(new Rook(0, 7,calcPosition(0, 7), 'w')));
        p2Pieces.push_back(*(new Rook(7, 7,calcPosition(7, 7), 'w')));
        p2Pieces.push_back(*(new Knight(1, 7,calcPosition(1, 7), 'w')));
        p2Pieces.push_back(*(new Knight(6, 7,calcPosition(6, 7), 'w')));
        p2Pieces.push_back(*(new Bishop(2, 7,calcPosition(2, 7), 'w')));
        p2Pieces.push_back(*(new Bishop(5, 7,calcPosition(5, 7), 'w')));
        p2Pieces.push_back(*(new Queen(3, 7,calcPosition(3, 7), 'w')));
        p2Pieces.push_back(*(new King(4, 7,calcPosition(4, 7), 'w')));
        
        //Initialize the pawns for both players
        for (int i = 0; i < boardSize; i++) {
            p1Pieces.push_back(*(new Pawn(i, 0,calcPosition(i, 0), 'b')));
            p2Pieces.push_back(*(new Pawn(i, 6,calcPosition(i, 6), 'w')));
        }
    }
    
    if (isEmpty) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                std::string position = calcPosition(i, j);
                board[i][j].setX(i);
                board[i][j].setY(j);
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
            std::string position = calcPosition(i, 0);
            board[i][0].setX(i);
            board[i][0].setY(0);
            board[i][0].setPos(position);
            board[i][0].setPiece(&((p1Pieces.at(i))));
            
            //Set x, y, position and piece for row 2
            position = calcPosition(i, 1);
            board[i][1].setX(i);
            board[i][1].setY(1);
            board[i][1].setPos(position);
            board[i][1].setPiece(&((p1Pieces.at(i+8))));
            
            
            //Set x, y, position and piece for row 7
            position = calcPosition(i, 7);
            board[i][7].setX(i);
            board[i][7].setY(7);
            board[i][7].setPos(position);
            board[i][7].setPiece(&((p2Pieces.at(i))));
            
            //Set x, y, position and piece for row 6
            position = calcPosition(i, 6);
            board[i][6].setX(i);
            board[i][6].setY(6);
            board[i][6].setPos(position);
            board[i][6].setPiece(&((p2Pieces.at(i+8))));
        }
        
        //Initialize empty cells
        for (int i = 2; i < 6; i++) {
            for (int j = 2; j < 6; j++) {
                std::string position = calcPosition(i, j);
                board[i][j].setX(i);
                board[i][j].setY(j);
                board[i][j].setPos(position);
                board[i][j].setPiece(NULL);
            }
        }
    }
}


