#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Dungeon.h"

/**
 * Game controls the overall gameplay loop and interactions.
 */
class Game {
private:
    Player player;
    Dungeon dungeon;
    bool running;

    void processInput(const std::string& input);
    void handleMovement(const std::string& direction);
    void handleCombat();

public:
    Game();

    void start();   // initializes game
    void run();     // main game loop
    void displayStatus() const;
};

#endif