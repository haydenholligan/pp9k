#include "player.h"

Player::Player(int playerNum): game(NULL), playerNum(playerNum) {}

Player::~Player() {
    game = NULL;
}

void Player::setGame(Game *g) {
    game = g;
}

int Player::getPlayerNum() {
    return this->playerNum;
}

void Player::setPlayerNum(int num) {
   playerNum = num;
}