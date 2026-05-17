#include "Game.h"
#include <iostream>
#include <limits>
#include <cstdlib>

// ===== Constructor =====
Game::Game()
    : player(),
      dungeon(),
      currentRoom(nullptr),
      startRoom(nullptr),
      running(true)
{
    dungeon.setupDungeon();
}

// ===== Start Game =====
void Game::start() {
    std::string name;

    std::cout << "Enter player name: ";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);

    player = Player(name);

    startRoom = dungeon.getStartRoom();
    currentRoom = startRoom;

    if (!currentRoom) {
        std::cout << "ERROR: Failed to load start room!\n";
        exit(1);
    }

    std::cout << "Player created: " << player.getName() << "\n";
    std::cout << "You are now in the starting room.\n";
}

// ===== Main Loop =====
void Game::run() {
    std::string input;

    while (running) {

        displayStatus();

        std::cout << "\nCommand (north, south, east, west, attack, take, quit): ";
        std::getline(std::cin, input);

        processInput(input);

        // WIN CHECK (ONLY AFTER ACTION)
        if (currentRoom &&
            currentRoom->getId() == 7 &&
            currentRoom->hasTrophy &&

            player.hasTrophyItem()) {

            std::cout << "\n🎉 Congratulations! You escaped with the trophy!\n";
            running = false;
        }
    }
}

// ===== Input =====
void Game::processInput(const std::string& input) {

    if (input == "quit") {
        running = false;
        std::cout << "Exiting game...\n";
    }
    else if (input == "attack") {
        handleCombat();
    }
    else if (input == "take") {
        handleTake();
    }
    else if (input == "north" || input == "south" ||
             input == "east" || input == "west") {
        handleMovement(input);
    }
    else {
        std::cout << "Unknown command.\n";
    }
}

// ===== Movement =====
void Game::handleMovement(const std::string& direction) {

    if (!currentRoom) return;

    Room* nextRoom = nullptr;

    if (direction == "north") nextRoom = currentRoom->north;
    else if (direction == "south") nextRoom = currentRoom->south;
    else if (direction == "east")  nextRoom = currentRoom->east;
    else if (direction == "west")  nextRoom = currentRoom->west;

    if (!nextRoom) {
        std::cout << "You can't go that way.\n";
        return;
    }

    currentRoom = nextRoom;
    

    std::cout << "You moved " << direction << ".\n";
    std::cout << currentRoom->getDescription() << "\n";
    if (currentRoom->getId() == 2) {
    currentRoom->hasEnemy = true;
    currentRoom->monsterCount = 3;
    currentRoom->enemyHealth = 20;
}
    if (currentRoom->hasEnemy)
        std::cout << "👹 Enemy is here!\n";

    if (currentRoom->hasBoss)
        std::cout << "🔥 BOSS is here!\n";

    if (currentRoom->hasSword)
        std::cout << "⚔️ A sword is here!\n";

    if (currentRoom->isHealingRoom) {
        std::cout << "❤️ Healing energy restores you!\n";
        player.heal(25);
    }

    if (currentRoom->hasTrophy)
        std::cout << "🏆 Trophy is here!\n";
}

// ===== Combat =====
void Game::handleCombat() {

    if (!currentRoom || !currentRoom->hasEnemy) {
        std::cout << "Nothing to attack.\n";
        return;
    }

    int baseDamage = 13;

// progression scaling by room
if (currentRoom->getId() <= 2) {
    baseDamage = 13;   // early game
}
else if (currentRoom->getId() <= 4) {
    baseDamage = 16;   // mid game
}
else if (currentRoom->getId() <= 6) {
    baseDamage = 20;   // late game
}
else {
    baseDamage = 25;   // final area
}

int damage = baseDamage;

if (player.hasSwordItem()) {
    damage += 6;
}

    currentRoom->enemyHealth -= damage;

    std::cout << "You deal " << damage << " damage!\n";

    // ===== Enemy dead =====
    if (currentRoom->enemyHealth <= 0) {

        std::cout << "Enemy defeated!\n";
        currentRoom->hasEnemy = false;

        if (currentRoom->hasBoss) {
            std::cout << "🔥 BOSS DOWN! Trophy dropped!\n";
            currentRoom->hasTrophy = true;
            currentRoom->hasBoss = false;
        }
        else {
            currentRoom->hasTrophy = true;
        }

        return;
    }

    std::cout << "Enemy HP: " << currentRoom->enemyHealth << "\n";

    // ===== Enemy attack =====
    int enemyDamage = currentRoom->hasBoss ? 7 : 5;

    if (currentRoom->hasBoss && currentRoom->enemyHealth <= 20) {
        std::cout << "🔥 BOSS RAGE MODE!\n";
        enemyDamage = 12;
    }

    player.takeDamage(enemyDamage);

    std::cout << "Enemy hits you for " << enemyDamage << "\n";
    std::cout << "HP: " << player.getHealth() << "\n";

    if (player.getHealth() <= 0) {
        std::cout << "You died!\n";
        exit(0);
    }
}

// ===== TAKE =====
void Game::handleTake() {

    if (!currentRoom) return;

    if (currentRoom->hasTrophy) {
        player.setHasTrophy(true);
        currentRoom->hasTrophy = false;
        std::cout << "🏆 Trophy taken!\n";
    }

    if (currentRoom->hasSword) {
        player.setHasSword(true);
        currentRoom->hasSword = false;
        std::cout << "⚔️ Sword taken!\n";
    }
}

// ===== STATUS =====
void Game::displayStatus() const {

    std::cout << "\n=== STATUS ===\n";
    std::cout << "Player: " << player.getName() << "\n";
    std::cout << "HP: " << player.getHealth() << "\n";
    std::cout << "Trophy: " << (player.hasTrophyItem() ? "YES" : "NO") << "\n";
    std::cout << "Sword: " << (player.hasSwordItem() ? "YES" : "NO") << "\n";

    if (currentRoom) {
        std::cout << "Room: " << currentRoom->getId() << "\n";
        std::cout << currentRoom->getDescription() << "\n";

        std::cout << "Exits: ";
        if (currentRoom->north) std::cout << "north ";
        if (currentRoom->south) std::cout << "south ";
        if (currentRoom->east)  std::cout << "east ";
        if (currentRoom->west)  std::cout << "west ";
        std::cout << "\n";

        if (currentRoom->hasEnemy) {
    std::cout << "👹 Enemy is here!\n";
}
    }
    
        // ===== Trophy =====
if (currentRoom->hasTrophy) {
    std::cout << "🏆 Trophy available here\n";
}

// ===== Sword =====
if (currentRoom->hasSword) {
    std::cout << "⚔️ Sword available here\n";
}

}