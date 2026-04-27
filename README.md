# Escape-the-Dungeon


A command-line dungeon game where the player explores rooms, fights enemies, collects items, and escapes.

## Features
- Move between rooms
- Fight enemies
- Collect items
- Health system
- Escape the dungeon (win condition)

## Build
cmake -S . -B build
cmake --build build

## Run
./build/escape_the_dungeon

## Tests
ctest --test-dir build --verbose

