#ifndef ROOM_H
#define ROOM_H

#include <string>

// Forward declaration (for future enemy system upgrade)
class Enemy;

class Room {
public:

    // =====================================================
    // CONSTRUCTORS
    // =====================================================
    Room();
    Room(int id, const std::string& desc);

    // =====================================================
    // CORE INFO
    // =====================================================
    int getId() const;
    std::string getDescription() const;

    void setDescription(const std::string& desc);
    void display() const;

    // =====================================================
    // ROOM CONNECTIONS
    // =====================================================
    Room* north;
    Room* south;
    Room* east;
    Room* west;

    // =====================================================
    // ENEMY SYSTEM
    // =====================================================
    bool hasEnemy;
    int enemyHealth;

    // =====================================================
    // BOSS SYSTEM
    // =====================================================
    bool hasBoss;
    int bossHealth;

    // =====================================================
    // MULTI-MONSTER SYSTEM
    // =====================================================
    int monsterCount;

    // =====================================================
    // ITEMS / REWARDS
    // =====================================================
    bool hasTrophy;

    // =====================================================
    // WEAPON SYSTEM
    // =====================================================
    bool hasSword;

    // =====================================================
    // SPECIAL ROOM TYPES
    // =====================================================
    bool isHealingRoom;

    // =====================================================
    // FUTURE UPGRADE (ADVANCED ENEMY SYSTEM)
    // =====================================================
    Enemy* enemy;

private:

    // =====================================================
    // ROOM IDENTITY
    // =====================================================
    int id;
    std::string description;
};

#endif