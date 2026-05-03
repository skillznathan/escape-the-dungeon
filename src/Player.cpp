#include "Player.h"
#include "Enemy.h"
#include <iostream>

Player::Player() : name(""), health(100), attackPower(10) {}

Player::Player(const std::string& name) : name(name), health(100), attackPower(10) {}

std::string Player::getName() const {
    return name;
}

int Player::getHealth() const {
    return health;
}

int Player::getAttackPower() const {
    return attackPower;
}

void Player::takeDamage(int damage) {
    (void)damage;
}

void Player::heal(int amount) {
    (void)amount;
}

void Player::attack(Enemy& enemy) {
    std::cout << name << " attacks " << enemy.getName() << "!\n";
    enemy.takeDamage(attackPower);
}