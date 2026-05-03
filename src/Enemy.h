#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy {
private:
    std::string name;
    int health;
    int attackPower;

public:
    Enemy();
    Enemy(const std::string& name, int hp, int attack);

    std::string getName() const;
    int getHealth() const;
    int getAttackPower() const;

    void takeDamage(int damage);
    bool isDead() const;
};

#endif