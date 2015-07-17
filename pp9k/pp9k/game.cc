#include "game.h"

#include <string>
Game::Game() {
    
}

Game::~Game() {
    
}

//Set up the board
void Game::setup() {
    
    
    //Initialize memory for the tiles
    board = new Tile*[boardSize];
    for (int i = 0; i < boardSize; i++) {
        board[i] = new Tile[boardSize];
    }
    
    //Initialize the pieces for player 1
    p1Pieces.push_back(*(new Rook(0, 0,calcPosition(0, 0))));
    p1Pieces.push_back(*(new Rook(7, 0,calcPosition(7, 0))));
    p1Pieces.push_back(*(new Knight(1, 0,calcPosition(1, 0))));
    p1Pieces.push_back(*(new Knight(6, 0,calcPosition(6, 0))));
    p1Pieces.push_back(*(new Bishop(2, 0,calcPosition(2, 0))));
    p1Pieces.push_back(*(new Bishop(5, 0,calcPosition(5, 0))));
    p1Pieces.push_back(*(new Queen(3, 0,calcPosition(3, 0))));
    p1Pieces.push_back(*(new King(4, 0,calcPosition(4, 0))));
    
    //Initialize the pieces for player 2
    p2Pieces.push_back(*(new Rook(0, 7,calcPosition(0, 7))));
    p2Pieces.push_back(*(new Rook(7, 7,calcPosition(7, 7))));
    p2Pieces.push_back(*(new Knight(1, 7,calcPosition(1, 7))));
    p2Pieces.push_back(*(new Knight(6, 7,calcPosition(6, 7))));
    p2Pieces.push_back(*(new Bishop(2, 7,calcPosition(2, 7))));
    p2Pieces.push_back(*(new Bishop(5, 7,calcPosition(5, 7))));
    p2Pieces.push_back(*(new Queen(3, 7,calcPosition(3, 7))));
    p2Pieces.push_back(*(new King(4, 7,calcPosition(4, 7))));
    
    //Initialize the pawns for both players
    for (int i = 0; i < boardSize; i++) {
        p1Pieces.push_back(*(new Pawn(i, 0,calcPosition(i, 0))));
        p2Pieces.push_back(*(new Pawn(i, 6,calcPosition(i, 6))));
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
        
        //Set x, y, position and piece for row 6
        position = calcPosition(i, 6);
        board[i][6].setX(i);
        board[i][6].setY(6);
        board[i][6].setPos(position);
        board[i][6].setPiece(&((p2Pieces.at(i+8))));
        
        
        //Set x, y, position and piece for row 2
        position = calcPosition(i, 7);
        board[i][7].setX(i);
        board[i][7].setY(7);
        board[i][7].setPos(position);
        board[i][7].setPiece(&((p2Pieces.at(i))));
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

//uses the loser as the parameter so endGame can be called by player->resign
void Game::endGame(Player *loser) {
    
}

void Game::move(Piece *pc, std::string s) {
    
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

void Game::upgrade(Piece) {
    
}

void Game::updateBoard() {
    
}

void Game::setPosition(Piece *pc, std::string s) {
    
}