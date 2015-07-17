#include "player.h"

Player::Player(): numWins(0), game(NULL) {}

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