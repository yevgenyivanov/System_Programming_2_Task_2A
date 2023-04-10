#include "player.hpp"
Player::Player(std::string name){
    this->name = name;
}
int Player::cardesTaken(){return 0;}
int Player::stacksize(){return 0;}

// Player::~Player(){}