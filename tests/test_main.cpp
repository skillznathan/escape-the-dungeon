#include <iostream>
#include <cassert>

#include "../src/Enemy.h"
#include "../src/Player.h"
#include "../src/Room.h"
#include "../src/Dungeon.h"

void test_player_creation() {
    Player p("Hero");

    assert(p.getName() == "Hero");

    std::cout << "test_player_creation: PASS\n";
}

void test_room_creation() {
    Room r(1, "Starting Room");

    assert(r.getId() == 1);
    assert(r.getDescription() == "Starting Room");

    std::cout << "test_room_creation: PASS\n";
}

void test_dungeon_initialization() {
    Dungeon d;

    // even if empty for now, should not crash
    assert(d.getRoomCount() >= 0);

    std::cout << "test_dungeon_initialization: PASS\n";
}


int main() {
    std::cout << "Running tests...\n\n";

    test_player_creation();
    test_room_creation();
    test_dungeon_initialization();
    
    std::cout << "\nAll tests passed.\n";
    return 0;
}
