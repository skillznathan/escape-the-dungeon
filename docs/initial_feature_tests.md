# Initial Feature Test Cases

## Feature: Create Player

### Test 1: Normal Operation
- What it tests: Creating a player with a valid name
- Expected result: Player is created with correct name and health = 100
- Result: PASS

### Test 2: Edge Case
- What it tests: Creating a player with an empty name
- Expected result: Player is still created, name is empty string
- Result: PASS

### Test 3: Boundary Condition
- What it tests: Default health initialization
- Expected result: Health is always 100 when player is created with name
- Result: PASS

### CTest Output
(Paste your ctest --verbose output here)