#include "Player.h"

// Default constructor
Player::Player() {
    name = "";
    health = 0;
}

// Feature constructor
Player::Player(const std::string& name) {
    this->name = name;
    this->health = 100;
}

// Getters
std::string Player::getName() const {
    return name;
}

int Player::getHealth() const {
    return health;
}