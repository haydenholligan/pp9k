#include "player.h"

Player::Player(int playerNum): numWins(0), game(NULL), playerNumber(playerNum) {}

Player::~Player() {
    game = NULL;
}

void Player::resign() {
    //fix
    //game->endGame(this);
}

void Player::addWin() {
    numWins++;
}

void Player::setGame(Game *g) {
    game = g;
}


int Player::getPlayerNum() {
    return this->playerNumber;
}

void Player::setPlayerNum(int num) {
    playerNumber = num;
}