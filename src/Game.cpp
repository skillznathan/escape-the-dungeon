#include "Game.h"
#include <iostream>

// ===== Constructor =====
Game::Game() : player(), dungeon(), running(true) {
    dungeon.setupDungeon();
}

// ===== Start Game =====
void Game::start() {
    std::string name;

    std::cout << "Enter player name: ";
    std::getline(std::cin, name);

    player = Player(name);

    std::cout << "Player created: " << player.getName() << "\n";
}

// ===== Main Game Loop =====
void Game::run() {
    std::string input;

    while (running) {
        displayStatus();

        std::cout << "\nEnter command (move, attack, quit): ";
        std::getline(std::cin, input);

        processInput(input);
    }
}

// ===== Input Handler =====
void Game::processInput(const std::string& input) {
    if (input == "quit") {
        running = false;
        std::cout << "Exiting game...\n";
    }
    else if (input == "attack") {
        handleCombat();   // ✅ YOUR REQUIRED LINE
    }
    else if (input == "north" || input == "south" ||
             input == "east" || input == "west") {
        handleMovement(input);
    }
    else {
        std::cout << "Unknown command.\n";
    }
}

// ===== Movement (stubbed for now) =====
void Game::handleMovement(const std::string& direction) {
    (void)direction;
    std::cout << "You move...\n";
}

// ===== Combat System =====
void Game::handleCombat() {
    std::cout << "You attack the enemy!\n";
    std::cout << "Combat system not fully implemented yet.\n";

    // Example placeholder logic:
    // Enemy enemy("Goblin", 20, 5);
    // enemy.takeDamage(player.getAttackPower());
}

// ===== Status Display =====
void Game::displayStatus() const {
    std::cout << "\n=== STATUS ===\n";
    std::cout << "Player: " << player.getName() << "\n";
    std::cout << "Health: " << player.getHealth() << "\n";
}