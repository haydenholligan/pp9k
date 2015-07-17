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
    
    //Initialize the pieces
    //p1Pieces.push_back(new Piece()
    
    
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            std::string position = calcPosition(i, j);
            
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