#include "Enemy.h"
#include <iostream>

Enemy::Enemy() : name("Goblin"), health(30), attackPower(5) {}

Enemy::Enemy(const std::string& name, int hp, int attack)
    : name(name), health(hp), attackPower(attack) {}

std::string Enemy::getName() const {
    return name;
}

int Enemy::getHealth() const {
    return health;
}

int Enemy::getAttackPower() const {
    return attackPower;
}

void Enemy::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}

bool Enemy::isDead() const {
    return health <= 0;
}