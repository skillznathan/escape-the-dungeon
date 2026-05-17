# Escape the Dungeon

A command-line dungeon crawler game built in C++ where the player explores connected rooms, fights enemies, collects items, and attempts to escape the dungeon with the treasure.

---

## Project Overview

This project demonstrates object-oriented design in C++ using a text-based dungeon crawler. The player navigates a graph of rooms, engages in turn-based combat, collects items, and attempts to reach the final room.

The dungeon is manually constructed and includes combat scaling, item drops, healing mechanics, and a boss encounter.

---

## Current Features

### Implemented Features

- Room-based dungeon navigation (north, south, east, west)
- Turn-based combat system
- Enemy encounters in multiple rooms
- Boss fight with increased difficulty
- Item system:
  - Sword increases damage
  - Trophy used for win condition
- Healing room that restores player health
- Win condition: reach Treasure Room (Room 7) with the trophy
- Basic scaling combat system based on room progression

---

### ⚠️ Known Design Notes / Behavior

- Some rooms spawn or reassign items dynamically when entered
- Trophy can appear in multiple rooms during gameplay (design simplification)
- Enemy strength is currently scaled by room ID (not enemy type system)

---

## Build Instructions

Make sure CMake is installed.

```bash
cmake -S . -B build
cmake --build build

## Run
./build/escape_the_dungeon

## Tests
ctest --test-dir build --verbose

