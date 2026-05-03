#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Enemy; // needed because Enemy is used below

class Player {
private:
    std::string name;
    int health;
    int attackPower;

public:
    Player();
    Player(const std::string& name);

    std::string getName() const;
    int getHealth() const;

    int getAttackPower() const;   // ✅ here

    void attack(Enemy& enemy);    // ✅ here

    void takeDamage(int damage);
    void heal(int amount);
};

#endif