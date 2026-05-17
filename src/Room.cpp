#include "Room.h"
#include <iostream>

// ===== Default Constructor =====
Room::Room()
    : id(0),
      description("empty room"),
      north(nullptr),
      south(nullptr),
      east(nullptr),
      west(nullptr),
      enemy(nullptr),

      hasEnemy(false),
      hasTrophy(false),
      hasBoss(false),

      hasSword(false),
      isHealingRoom(false),

      enemyHealth(0),
      bossHealth(0),
      monsterCount(0)
{
}

// ===== Parameter Constructor =====
Room::Room(int id, const std::string& desc)
    : id(id),
      description(desc),
      north(nullptr),
      south(nullptr),
      east(nullptr),
      west(nullptr),
      enemy(nullptr),

      hasEnemy(false),
      hasTrophy(false),
      hasBoss(false),

      hasSword(false),
      isHealingRoom(false),

      enemyHealth(0),
      bossHealth(0),
      monsterCount(0)
{
}

// ===== Getters =====
int Room::getId() const {
    return id;
}

std::string Room::getDescription() const {
    return description;
}

// ===== Setter =====
void Room::setDescription(const std::string& desc) {
    description = desc;
}

// ===== Display Room Info =====
void Room::display() const {

    std::cout << "\nRoom " << id << ": " << description << "\n";

    // ===== Connections =====
    std::cout << "Exits: ";
    if (north) std::cout << "north ";
    if (south) std::cout << "south ";
    if (east)  std::cout << "east ";
    if (west)  std::cout << "west ";
    std::cout << "\n";

    // ===== Monsters =====
    if (hasEnemy) {
        std::cout << "👹 Monsters in room: " << monsterCount << "\n";
        std::cout << "Enemy HP: " << enemyHealth << "\n";
    }

    // ===== Boss =====
    if (hasBoss) {
        std::cout << "🔥 BOSS HP: " << bossHealth << "\n";
    }

    // ===== Items =====
    if (hasSword) {
        std::cout << "⚔️ A sword is here!\n";
    }

    if (hasTrophy) {
        std::cout << "🏆 A trophy is here!\n";
    }

    // ===== Special Room =====
    if (isHealingRoom) {
        std::cout << "❤️ This room heals you!\n";
    }
}