# Interactive-Conways-Game-of-Life
Interactive implementation of Conway's Game of Life written in C++ using the Raylib graphics library.

Unlike a basic simulation, this version allows the user to interactively create patterns using the mouse.

## Features

* Classic cellular automaton rules implementation
* Interactive grid system allowing players to draw custom cell patterns
* Play and pause mechanics to freeze time and edit the board safely
* Smooth rendering using the Raylib library

## How the Game Works

The simulation runs on a standard game loop and follows Conway's fundamental rules:

1. Player input is checked (mouse for editing, keyboard for pausing/resuming).
2. If the simulation is running, the grid updates based on the neighbor count of each cell:
   - Any live cell with 2 or 3 live neighbors survives.
   - Any dead cell with exactly 3 live neighbors becomes a live cell.
   - All other live cells die (from underpopulation or overpopulation).
3. The generation counter increases over time.
4. The screen is redrawn every frame showing the updated grid and text UI.

Players can pause the game at any moment to draw their own starting patterns (like Gliders, Blinkers, or custom shapes) and then press Space to resume the simulation and watch them evolve.

## Game States

The program constantly switches between two main states:

* **Paused** - The simulation is frozen. Cells do not die or reproduce, allowing the player to paint new cells on the grid using the mouse.
* **Running** - The simulation updates automatically frame by frame according to the rules of life.

## Controls

* **Left Mouse Button (Click or Hold)** - Spawn live cells on the grid
* **Right Mouse Button (Click or Hold)** - Deleting cells from the grid
* **SPACE** - Play / Pause the simulation

  
https://github.com/user-attachments/assets/ae428e19-5917-4a1c-93e8-d39174938b19
