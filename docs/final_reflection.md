# Final Reflection — Escape the Dungeon

## Scope Statement

### Original Planned Features
| Feature | Status |
|---|---|
| Player movement between rooms | Done |
| Enemy combat system | Done |
| Item collection system | Done |
| Health and healing system | Done |
| Boss battle | Done |
| Trophy / win condition | Done |
| Sword damage upgrade | Done |
| Multiple connected rooms | Done |
| Unit tests with CTest | Done |
| Advanced enemy AI | Missing |
| Inventory expansion | Stubbed |
| Save/load system | Cut |

### Features Added in Final Submission
- Progressive enemy difficulty scaling
- Boss rage mode
- Healing room
- Expanded room structure and dungeon flow
- Updated README documentation
- Additional testing and gameplay balancing

---

# Prompt 1: Plan vs. Reality

At the start of the project, I planned to create a simple dungeon crawler with movement, combat, and item collection. Most of the original gameplay systems were completed successfully, including room navigation, enemy encounters, item pickups, healing, and a final boss battle.

Some features changed significantly during development. Originally, I planned to implement a larger inventory system with multiple item types, but I realized the current project architecture was not flexible enough for a full inventory design. Instead, I simplified the system into boolean item ownership, such as `hasSword` and `hasTrophy`.

Another feature that changed was enemy progression. Initially, all enemies used nearly identical combat values, which made later rooms feel weak and repetitive. During development, I added progressive enemy health scaling in `Dungeon.cpp` and additional boss mechanics in `Game::handleCombat()` to make later encounters more challenging.

I also originally considered adding a save/load feature, but I decided to cut it because it would require file serialization and more extensive architecture changes than I could complete within the project timeline.

---

# Prompt 2: Design Decisions You Would Change

If I restarted this project, I would redesign the combat and room systems to separate gameplay data from gameplay logic more cleanly.

Currently, the `Room` class stores many gameplay flags directly, including:
- `hasEnemy`
- `hasBoss`
- `hasSword`
- `hasTrophy`
- `enemyHealth`

This caused `Game.cpp` to become tightly coupled to room state. The `handleCombat()` method directly modifies room properties instead of interacting with dedicated enemy objects.

If I redesigned the project, I would create:
- an `Enemy` class,
- an `Item` class,
- and possibly a `CombatManager` class.

That would allow rooms to contain collections of enemies and items instead of hardcoded booleans.

I would also separate display code from gameplay logic. Right now, methods like `displayStatus()` and `handleMovement()` both contain game logic and UI output. Separating those concerns would make the code easier to maintain and easier to convert into a graphical interface later.

Another design issue is room linking. In `Dungeon.cpp`, rooms are manually connected using pointers such as:

```cpp
start->north = hallway;
hallway->south = start;

Prompt 3: What You Learned
Technical Learning

I became much more comfortable using classes, pointers, and object relationships in C++. Building the room navigation system helped me understand directional linking between objects.


Design Learning

I learned why separation of concerns matters in software design. As the project grew, Game.cpp became responsible for too many tasks, including combat logic, movement, UI printing, and win-condition checking. This made the file harder to modify and debug.

That experience made software design principles more real to me, especially the importance of splitting responsibilities across multiple classes.

Process Learning

I improved my Git and GitHub workflow significantly during this project. Using feature branches, pull requests, merges, and self-reviews became much more natural after repeating the workflow multiple times.

I also learned the importance of testing frequently instead of waiting until the end. Earlier in the project, I sometimes introduced bugs by making multiple changes before compiling. By the final stages, I was testing after nearly every major change.




Prompt 4: What's Left to Finish

If I continued this project, these would be the next priorities:

Full inventory system
The game currently only supports simple boolean item ownership. A real inventory system would allow multiple weapons, consumables, and equipment.
Dedicated Enemy class
Enemy logic is currently stored directly inside Room objects. A dedicated class would improve combat design and scalability.
Expanded dungeon map
The dungeon currently has only seven rooms. Adding branching paths and optional areas would improve replayability.
Save and load system
The game currently resets every session. Save support would make progression more meaningful.




Prompt 5: Workflow Reflection

The feature-branch and pull-request workflow became much more comfortable over time. Creating branches, committing changes, pushing code, and merging pull requests now feels much more natural than it did at the beginning of the semester.

If I were collaborating with another developer, the workflow would become even more important. Feature branches and pull requests help prevent conflicts and make code reviews easier. Testing before merging would also matter more because broken code would affect the whole team instead of only my own local project.


Prompt 6: AI Use

I used AI tools primarily for debugging help, gameplay balancing ideas, and explaining C++ errors. AI was especially useful when I encountered issues with combat scaling, room connections, and understanding why certain gameplay logic was not working correctly.

There were also situations where the AI suggested overly complicated solutions that did not fit the scale of my project. In those cases, I simplified the implementation to better match my current architecture and experience level.