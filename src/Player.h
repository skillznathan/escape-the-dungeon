#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    int health;

    bool hasTrophy;
    bool hasSword;

public:
    Player();
    Player(const std::string& name);

    // ===== Getters =====
    std::string getName() const;
    int getHealth() const;

    bool hasTrophyItem() const;
    bool hasSwordItem() const;

    // ===== Setters / Actions =====
    void setHasTrophy(bool value);
    void setHasSword(bool value);

    void takeDamage(int amount);
    void heal(int amount);

    void addSword();
};

#endif