#include "player.h"
#include <iostream>
extern bool dbg;

Player::Player(int playerNum, Game *g): game(g), playerNum(playerNum) {
    if (dbg) std::cout << "calling player constructor, playerNum: " << playerNum << std::endl;
}

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

