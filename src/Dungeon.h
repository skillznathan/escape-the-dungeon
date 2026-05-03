#ifndef DUNGEON_H
#define DUNGEON_H

#include <vector>
#include "Room.h"

/**
 * Dungeon manages all rooms and layout.
 */
class Dungeon {
private:
    std::vector<Room> rooms;

public:
    Dungeon();

    Room& getRoom(int id);
    int getRoomCount() const;

    void setupDungeon(); // initialize rooms
};

#endif