# Diagonal Sudoku Solver with Graphical Display

A **Diagonal Sudoku Solver** implemented in **C++** using the **SFML (Simple and Fast Multimedia Library)**.  
The program solves a 9×9 Sudoku puzzle entered by the user and visually displays the solved grid in a graphical window.

---

## Project Overview
This application allows users to input an unsolved Sudoku puzzle through the terminal, solves it using a **backtracking algorithm**, and renders the completed puzzle in a graphical window using SFML.

In addition to standard Sudoku rules, this solver also enforces a **diagonal constraint**, ensuring that numbers do not repeat along both main diagonals.

---

## How It Works

### 1. Input Sudoku Puzzle
- The user enters the Sudoku grid through the terminal.
- Empty cells are represented using `0`.

### 2. Sudoku Solver Logic
- The solver uses a **backtracking algorithm** to fill empty cells.
- For each empty cell, numbers from **1 to 9** are tested.

A number is placed only if it satisfies all constraints:
- No repetition in the same row
- No repetition in the same column
- No repetition in the same 3×3 subgrid
- No repetition along both diagonals (extra constraint)

### 3. Graphical Display using SFML
- After solving, a **600×600 SFML window** is created.
- The Sudoku grid is drawn using:
  - **Thick black lines** for 3×3 box boundaries
  - **Thin gray lines** for individual cells
- Numbers are rendered inside cells using a font file (`arial.ttf`).

---

## Visual Output
- Displays a complete Sudoku board with clear separation of rows, columns, and subgrids.
- Each solved number is shown neatly within its corresponding cell.
- The grid resembles a standard Sudoku layout with diagonal constraints applied.

---

## Key Features
- Solves valid **9×9 diagonal Sudoku puzzles**
- Uses an efficient **backtracking algorithm**
- Graphical rendering with **SFML**
- Clear visualization of grid and numbers
- Simple terminal-based input with GUI output

---

## Requirements
- **C++ compiler** (supporting C++11 or later)
- **SFML library** installed
- `arial.ttf` font file present in the project directory

---
lsfml-system
