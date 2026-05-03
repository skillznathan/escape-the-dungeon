#include "Dungeon.h"
#include <iostream>

Dungeon::Dungeon() {
    // TODO: initialize dungeon layout
    std::cout << "Dungeon created\n";
}

Room& Dungeon::getRoom(int id) {
    // TODO: implement properly later

    static Room dummyRoom; // safe fallback so program doesn't crash
    (void)id;

    return dummyRoom;
}

int Dungeon::getRoomCount() const {
    return static_cast<int>(rooms.size());
}

void Dungeon::setupDungeon() {
    // TODO: create rooms and connect them
    std::cout << "Dungeon setup not implemented yet\n";
}