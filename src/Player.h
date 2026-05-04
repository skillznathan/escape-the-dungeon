#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    int health;

public:
    Player();
    Player(const std::string& name);

    std::string getName() const;
    int getHealth() const;
};

#endif