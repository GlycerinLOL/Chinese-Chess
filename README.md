# Chinese-Chess (中國象棋 / 象棋對局系統)

Chinese-Chess is a C++ implementation of Chinese Chess (Xiangqi).  
This project was originally developed as an Object-Oriented Programming (OOP) course project.  
It includes:
- A console-mode version for fast logic testing.
- A board/GUI version with clickable pieces for human vs human play.

The focus of the project is clean game logic, rule correctness, and class design for each piece type.

> Status: Work in progress

---

## ✨ Features

### Core Game Logic
- Full set of Xiangqi pieces:
  - General / King (將 / 帥)
  - Advisor / Guard (士 / 仕)
  - Elephant / Minister (象 / 相)
  - Horse (馬)
  - Chariot / Rook (車)
  - Cannon (炮)
  - Soldier / Pawn (卒 / 兵)
- Turn-based gameplay (Red vs Black).
- Legal move validation for every piece type:
  - Horse "leg blocking" rule.
  - Cannon's unique capture rule (must jump exactly one piece to capture).
  - Elephant cannot cross the river.
  - Advisors restricted to the palace.
  - General cannot leave the palace.
  - Face-to-face rule: the two Generals (將/帥) cannot directly face each other with no pieces in between.
- Check / checkmate detection (將軍判斷、遊戲結束判斷).

### Two Frontends
1. **Console Mode** (`Project2_Console_Mode/`)
   - Text-based board rendering.
   - Input moves using coordinates.
   - Great for debugging rules and testing AI in the future.

2. **Board Game / GUI Mode** (`Project2 Chinese Board Game/`)
   - Visual chessboard.
   - Click a piece, then click a destination to move.
   - Highlights valid moves / prevents illegal moves (depending on build status).

---

## 🧠 Project Goals

- Practice OOP design in C++:
  - Each piece is its own class, likely inheriting from a common `Piece` base class.
  - The board is managed by a `Board` (or similar) class that tracks piece positions.
  - A `Game` (or similar) controller class manages turns, win conditions, etc.
- Separate game **logic** from **UI**:
  - The console frontend and the GUI frontend reuse the same rules and state logic.
  - This makes it easier to extend (AI bots, networking, replay system, etc.).

---

## 🗂 Repository Structure

```text
Chinese-Chess/
├─ Project2 Chinese Board Game/
│  ├─ ... (GUI / board rendering version)
│  ├─ Game controller for interactive play
│  └─ Mouse/board coordinate mapping
│
├─ Project2_Console_Mode/
│  ├─ ... (console version)
│  ├─ Text-based board printing
│  └─ Command-line move input
│
├─ README.md
└─ (C++ headers / sources for pieces, board state, move validation, etc.)
```

> The GUI version and console version share the same chess rules, but expose different input/output layers.

---

## 🏗 Build & Run

> Note: The exact build commands may differ depending on your environment / compiler setup.  
> Below is a reference setup that works for most standard g++/clang++ toolchains.

### Requirements
- A C++17 (or newer) compiler (e.g. `g++` or `clang++`)
- A standard build environment for your OS
- For the GUI version: the project may rely on a graphics library (e.g. Win32 GDI / SDL / etc.).  
  Please check the source in `Project2 Chinese Board Game/` for the specific library includes.

### Console Mode (recommended for first run)
From inside `Project2_Console_Mode/`:

```bash
g++ -std=c++17 -O2 -o chinese_chess_console *.cpp
./chinese_chess_console
```

Typical flow:
1. The board is printed on screen.
2. Players take turns entering moves (e.g. source coordinate -> destination coordinate).
3. The engine rejects illegal moves (moving through blocked horse leg, illegal cannon capture, leaving general in check, etc.).
4. When one side is checkmated, the program declares the winner.

### GUI / Board Game Mode
From inside `Project2 Chinese Board Game/`:

```bash
g++ -std=c++17 -O2 -o chinese_chess_gui *.cpp      $(pkg-config --cflags --libs <your_graphics_lib_if_any>)
./chinese_chess_gui
```

Interaction model:
- Click on one of your pieces.
- Valid destinations are shown / or only legal squares are accepted.
- Click a target square to move.

If you're on Windows and this project uses Win32 API, you can open the Visual Studio project/solution in this folder and build directly.

---

## ♟ Game Rules Implemented

- **Turn order**: Red moves first, then Black.
- **Move legality**:
  - Advisors move diagonally 1 step inside the palace.
  - Elephants move diagonally 2 steps but cannot cross the river and cannot be blocked.
  - Horses move in an L-shape, but cannot move if the "horse leg" is blocked.
  - Cannons move like Rooks:
    - Non-capture: slide any number of empty squares.
    - Capture: must jump exactly one piece and then land on an opponent piece.
  - Soldiers:
    - Move forward 1 step before crossing the river.
    - After crossing the river, they may also move horizontally.
    - No backward movement.
  - Generals stay in the 3×3 palace, 1-step orthogonal movement.
- **Face-to-face rule**:
  - The two Generals cannot be on the same file with no blocking pieces between them.
  - A move that exposes this is illegal.
- **Check / Checkmate detection**:
  - The engine can tell when a General is under attack ("將軍").
  - The game ends if a side has no legal move to escape.

---

## 🔮 Roadmap / Future Work

- [ ] Add AI opponent  
      - Minimax / alpha-beta search.
      - Simple evaluation: material score + king safety + pawn advancement.
- [ ] Add undo / move history.
- [ ] Add move highlighting and last-move trace in GUI.
- [ ] Add FEN-like serialization for Xiangqi board state.
- [ ] Online play (socket / P2P).
- [ ] Add unit tests for each piece's movement rules.

---

## 🤝 Contributions

This project started as an OOP coursework project and is still evolving.

If you want to:
- clean up code structure,
- add an AI player,
- port the GUI to a cross-platform library (SDL2, SFML, etc.),
- or write tests,

feel free to open a pull request or file an issue.

---

## 📜 License

[MIT License](/LICENSE)  
(If no LICENSE currently exists in the repo, you can add one; MIT is typical for student projects and allows reuse with attribution.)

---

## 🏁 Credits

- Original project: **OOP Project 2 Chinese Chess 象棋**
- Repo owner / maintainer: [GlycerinLOL](https://github.com/GlycerinLOL)
- Forked / evolved from prior work under the same course project line

Thanks to everyone who helped test moves, find illegal horse legs, and make the cannon behave 😄
