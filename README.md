# Adventure_Quest_Multi-Player_Game-C-
# Adventure Quest - README

## Overview
Adventure Quest is a two-player board game built using C++ and SFML (Simple and Fast Multimedia Library). Players navigate through a dynamically generated board, collecting items, overcoming obstacles, and racing to reach the center cell.

## Features
- **Two-Player Gameplay**: Players take turns moving across the board.
- **Dynamic Board Generation**: Board size increases with each level.
- **Item System**: 
  - **Coins**: Gold (+10 points) and Silver (+5 points)
  - **Helpers**: Sword, Shield, Water, Key
  - **Obstacles**: Fire, Snake, Ghost, Lion, Lock
- **Turn-Based Mechanics**: Players alternate turns with special skip-turn penalties.
- **Level Progression**: 4 levels with increasing difficulty.

## How to Play
1. **Controls**:
   - Player 1: Press 'A' to move
   - Player 2: Press 'K' to move
2. **Movement**:
   - Players move along a predefined zig-zag path
   - Player 1 moves from start to center
   - Player 2 moves from end to center
3. **Winning**:
   - First player to reach the red center cell wins the level
   - Complete all 4 levels to win the game

## Item Interactions
| Item       | Effect | Counter |
|------------|--------|---------|
| Gold Coin  | +10 points | - |
| Silver Coin| +5 points | - |
| Sword      | -40 points | Counters Snake/Lion |
| Shield     | -30 points | Counters Ghost |
| Water      | -50 points | Counters Fire |
| Key        | -70 points | Unlocks Lock |
| Fire       | Blocks 2 turns | Water |
| Snake      | Blocks 3 turns, moves back | Sword |
| Ghost      | Blocks 1 turn | Shield |
| Lion       | Blocks 4 turns | Sword |
| Lock       | Blocks until key is found | Key |

## Technical Details
- **Dependencies**: SFML 2.5+
- **Files**:
  - `Board.cpp/h`: Handles board generation, item placement, and drawing
  - `Item.cpp/h`: Base class and implementations for all game items
  - `Player.cpp/h`: Player movement, inventory, and interaction logic
  - `main.cpp`: Game loop and level progression

## Building and Running
1. Install SFML libraries
2. Compile all source files with SFML linked
3. Run the executable

## Future Improvements
- Graphical UI enhancements
- Sound effects
- More items and obstacles
- Customizable board sizes

Enjoy the game! The first player to complete all levels wins the Adventure Quest!
