cmake_minimum_required(VERSION 3.10)
project(EscapeDungeon)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

add_library(game_lib
    src/Player.cpp
    src/Enemy.cpp
    src/Room.cpp
    src/Game.cpp
    src/Dungeon.cpp
)
target_include_directories(game_lib PUBLIC include)

add_executable(escape_dungeon src/main.cpp)
target_link_libraries(escape_dungeon game_lib)

add_executable(tests tests/test_main.cpp)
target_link_libraries(tests game_lib)

add_test(NAME FeatureTests COMMAND tests)