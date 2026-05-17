#ifndef GAME_H
#define GAME_H

#include <string>
#include "Player.h"
#include "Dungeon.h"
#include "Room.h"

class Game {
private:
    Player player;
    Dungeon dungeon;

    Room* currentRoom;
    Room* startRoom;

    bool running;

    // ===== GAME STATE =====
    bool hasTrophy;

    // ===== BOSS STATE =====
    bool bossDefeated;

    void processInput(const std::string& input);

    void handleMovement(const std::string& direction);
    void handleCombat();
    void handleTake();

public:
    Game();

    void start();
    void run();

    void displayStatus() const;

    // ===== Boss system helper =====
    bool isBossRageMode(Room* room);
};

#endif