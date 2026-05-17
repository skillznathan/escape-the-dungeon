#ifndef DUNGEON_H
#define DUNGEON_H

#include <vector>
#include "Room.h"


class Dungeon {
private:
    std::vector<Room*> rooms;

public:
    Dungeon();

    Room& getRoom(int id);
    int getRoomCount() const;

    void setupDungeon(); 

    Room* getStartRoom() const;
};

#endif