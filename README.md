# C Matrix Strategy Game (Pathfinding Simulation)

This project is a C-based application that generates a randomized NxN grid map and solves a pathfinding problem between two points using specific procedural generation rules.

## 🚀 Overview

The program simulates a navigation system on a dynamically generated map. It places a Start Point (A) and a Target Point (B), fills the environment with obstacles (X) and open paths (O), and calculates a valid route.

## ✨ Features

* [cite_start]**Dynamic Grid Generation:** User-defined matrix size (N x N), where N > 6[cite: 5].
* **Procedural Placement Rules:**
  * [cite_start]**Distance Constraint:** Points A and B are placed randomly with a minimum **Manhattan Distance of 4 units**[cite: 8].
  * **Obstacle Logic:** The grid is filled with obstacles ('X') and free cells ('O'). [cite_start]The algorithm ensures **no more than 2 obstacles** appear consecutively (horizontally or vertically) to prevent impossible maps[cite: 11].
* **Pathfinding Algorithm:**
  * [cite_start]Supports movement in **8 directions** (vertical, horizontal, and diagonal)[cite: 12].
  * [cite_start]If a valid path is found, the route is marked with step indices (1, 2, 3...)[cite: 15].
* [cite_start]**Auto-Retry Mechanism:** If the randomly generated map is unsolvable, the system automatically regenerates the grid up to **5 times** to find a valid solution[cite: 17, 18].

## 🛠️ Installation & Usage

### Prerequisites
You need a C compiler (like GCC) to run this project.

### Compilation
Open your terminal and run:

```bash
gcc main.c -o matrix_pathfinder
