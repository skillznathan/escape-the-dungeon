#include "Dungeon.h"
#include <iostream>
#include <stdexcept>

Dungeon::Dungeon() {
    std::cout << "Dungeon created\n";
}

// ===== BUILD DUNGEON =====
void Dungeon::setupDungeon() {

    std::cout << "Building dungeon...\n";

    // =====================================================
    // CREATE ROOMS
    // =====================================================

    Room* start      = new Room(1, "Start Room");
    Room* hallway    = new Room(2, "Dark Hallway");
    Room* armory     = new Room(3, "Ancient Armory");
    Room* healRoom   = new Room(4, "Healing Shrine");
    Room* monsterDen = new Room(5, "Monster Den");
    Room* bossRoom   = new Room(6, "Boss Chamber");
    Room* treasureRoom = new Room(7, "Treasure Room");

    // =====================================================
    // START ROOM
    // =====================================================
    start->hasEnemy = true;
    start->enemyHealth = 30;
    start->monsterCount = 1;
    start->hasBoss = false;
    start->hasTrophy = true;

    // =====================================================
    // HALLWAY (2 enemies)
    // =====================================================
    hallway->hasEnemy = true;
    hallway->monsterCount = 2;
    hallway->enemyHealth = 45;
    hallway->hasBoss = false;
    hallway->hasTrophy = true;

    // =====================================================
    // ARMORY (4 enemies + sword reward)
    // =====================================================
    armory->hasEnemy = true;
    armory->monsterCount = 4;
    armory->enemyHealth = 60;
    armory->hasBoss = false;
    armory->hasSword = true;
    armory->hasTrophy = false;

    // =====================================================
    // HEALING ROOM (no enemies, healing loot)
    // =====================================================
    healRoom->hasEnemy = false;
    healRoom->monsterCount = 0;
    healRoom->enemyHealth = 0;
    healRoom->hasBoss = false;
    healRoom->hasSword = true;
    healRoom->hasTrophy = true;
    healRoom->isHealingRoom = true; 

    // =====================================================
    // MONSTER DEN (3 enemies)
    // =====================================================
    monsterDen->hasEnemy = true;
    monsterDen->monsterCount = 3;
    monsterDen->enemyHealth = 90;
    monsterDen->hasBoss = false;
    monsterDen->hasTrophy = false;

    // =====================================================
    // BOSS ROOM
    // =====================================================
    bossRoom->hasEnemy = true;
    bossRoom->hasBoss = true;
    bossRoom->enemyHealth = 105;
    bossRoom->bossHealth = 105;
    bossRoom->hasTrophy = false;

    // =====================================================
    // TREASURE ROOM (reward room)
    // =====================================================
    treasureRoom->hasEnemy = false;
    treasureRoom->hasBoss = false;
    treasureRoom->hasTrophy = true; 

    // =====================================================
    // CONNECT ROOMS
    // =====================================================

start->north = hallway;
hallway->south = start;

// 2 → 3 (THIS WAS MISSING)
hallway->south = armory;
armory->north = hallway;

// 3 → 4
armory->east = healRoom;
healRoom->west = armory;

// 4 → 5
healRoom->north = monsterDen;
monsterDen->south = healRoom;

// 5 → 6
monsterDen->north = bossRoom;
bossRoom->south = monsterDen;

// 6 → 7
bossRoom->west = treasureRoom;
treasureRoom->east = bossRoom;
   

    // =====================================================
    // STORE ROOMS
    // =====================================================

    rooms.push_back(start);
    rooms.push_back(hallway);
    rooms.push_back(armory);
    rooms.push_back(healRoom);
    rooms.push_back(monsterDen);
    rooms.push_back(bossRoom);

    std::cout << "Dungeon setup complete.\n";
}

// ===== GET ROOM =====
Room& Dungeon::getRoom(int id) {

    for (Room* room : rooms) {

        if (room->getId() == id) {
            return *room;
        }
    }

    throw std::runtime_error("Room not found");
}

// ===== START ROOM =====
Room* Dungeon::getStartRoom() const {

    if (rooms.empty()) {
        return nullptr;
    }

    return rooms[0];
}

// ===== ROOM COUNT =====
int Dungeon::getRoomCount() const {
    return static_cast<int>(rooms.size());
}