#include "Player.h"
#include <iostream>

// ===== Constructors =====
Player::Player()
    : name("Unknown"),
      health(100),
      hasTrophy(false),
      hasSword(false)
{
}

Player::Player(const std::string& name)
    : name(name),
      health(100),
      hasTrophy(false),
      hasSword(false)
{
}

// ===== Getters =====
std::string Player::getName() const {
    return name;
}

int Player::getHealth() const {
    return health;
}

bool Player::hasTrophyItem() const {
    return hasTrophy;
}

bool Player::hasSwordItem() const {
    return hasSword;
}

// ===== Setters =====
void Player::setHasTrophy(bool value) {
    hasTrophy = value;
}

void Player::setHasSword(bool value) {
    hasSword = value;
}

// ===== Combat =====
void Player::takeDamage(int amount) {
    health -= amount;

    if (health < 0)
        health = 0;
}

// ===== Healing =====
void Player::heal(int amount) {
    health += amount;

    if (health > 100)
        health = 100;
}

// ===== Pickup Sword =====
void Player::addSword() {
    hasSword = true;
    std::cout << "⚔️ You picked up a sword!\n";
}