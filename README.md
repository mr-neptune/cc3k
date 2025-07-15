# Chamber Claw 3000

**A Dungeon‑Crawler Adventure in C++**

---

## 🚀 Project Overview

Chamber Claw 3000 is a dungeon‑like, text‑based RPG built entirely in modern C++. You take the reins of a brave adventurer, delving into perilous chambers, battling fearsome foes, gathering glittering treasures, and leveling up your hero. Designed with ideal Object‑Oriented principles in mind, this game emphasizes **low coupling**, **high cohesion**, and **modularity**, making future enhancements a breeze.

## 🎯 Key Features

* **Explore Procedurally‑Generated Chambers:** No two runs are the same—every chamber holds new surprises.
* **Combat System:** Fight a variety of enemies with dynamic behaviors and loot tables.
* **Treasure & Loot:** Collect gold, weapons, armor, and magical artifacts to power up your character.
* **Leveling & Progression:** Gain experience, unlock new abilities, and customize your playstyle.
* **Clean, Modular Codebase:** Each component focuses on a single responsibility for maximum modifiability.

## 🏗️ Architecture & Design

Chamber Claw 3000 is partitioned into minimal‑sized components. Each file addresses only one aspect of the game’s functionality, drastically reducing side‑effects when you extend or refactor.

### Major Modules

* **Game Engine:** Core loop, state management, input/output handling.
* **Entities:** Definitions for `Character`, `Enemy`, `Item`, and their hierarchies.
* **Systems:** Combat resolution, collision detection, inventory management.
* **Utilities:** Logging, configuration parsing, random dungeon generation.

### Employed Design Patterns

* **Observer Pattern:** Real‑time notifications between game entities (e.g., health updates, event broadcasting).
* **Decorator Pattern:** Dynamically attach new behaviors or stat buffs to items and characters.
* **Factory Pattern:** Simplified creation of enemies, items, and levels without exposing object‑construction logic.
* **(…and more to come!)**

*Have fun clawing your way through the chambers, and don’t forget to stay hydrated—dragons can be thirsty!*
