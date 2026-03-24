# CPP's — C++ Modules

[Leia em Português](README.pt.md)

> Repository containing all exercises from the 42 C++ modules.  
> Each module progressively introduces new concepts of the language — from the basics to advanced topics.

---

## 📁 Repository Structure

```
cpp/
├── cpp00/
│   ├── ex00/   → Megaphone
│   └── ex01/   → Phonebook
├── cpp01/
│   ├── ex00/   → BraiiiiiiinnnzzzZ
│   ├── ex01/   → Moar brainz!
│   ├── ex02/   → HI THIS IS BRAIN
│   ├── ex03/   → Unnecessary violence
│   ├── ex04/   → Sed is for losers
│   ├── ex05/   → Harl 2.0
│   └── ex06/   → Harl filter
└── ...
```

---

## 🗂️ Modules

<details>
<summary><strong>CPP00 — Namespaces, Classes, I/O</strong></summary>

### Concepts covered
- Namespaces (`std::`)
- Classes, attributes and methods
- Encapsulation (`private` / `public`)
- Getters and Setters
- Static variables and methods
- Constructor and Destructor
- `std::cin`, `std::cout`, `std::getline`

---

### ex00 — Megaphone

**Goal:** Introduction to C++ and the use of `std::cout`.

The program takes words as arguments and prints them in uppercase.  
If no arguments are provided, it prints a noise message.

**Example:**
```bash
./megaphone "hello world"
HELLO WORLD

./megaphone
* LOUD AND UNBEARABLE NOISE *
```

**Files:**
| File | Description |
|---|---|
| `megaphone.cpp` | Main logic, iterates over `argv[]` and converts with `std::toupper()` |

---

### ex01 — Phonebook

**Goal:** Introduction to classes and user interaction.

A phonebook with a capacity of 8 contacts. When full, the oldest contact is replaced by the new one.

**Available commands:**
| Command | Action |
|---|---|
| `ADD` | Adds a new contact |
| `SEARCH` | Lists and searches contacts by index |
| `EXIT` | Exits the program |

**Contact fields:** First name, Last name, Nickname, Phone number, Darkest secret.

> ⚠️ In the SEARCH table, names longer than 10 characters are truncated with `.` — e.g. `"JoaoMartins"` → `"JoaoMarti."`

**Files:**
| File | Description |
|---|---|
| `main.cpp` | Main loop, reads input and creates contacts |
| `Contact.hpp/.cpp` | Class holding each contact's data |
| `Phonebook.hpp/.cpp` | Class managing the array of 8 contacts |
| `utils.hpp/.cpp` | Helper functions: `Display()`, `IsNumber()`, `Stoi()`, `HandleSignal()` |

</details>

---

<details>
<summary><strong>CPP01 — Memory allocation, pointers to members, references and switch statements</strong></summary>

### Concepts covered
- Stack vs heap allocation (`new` / `delete`)
- Arrays of objects on the heap
- Pointers and references
- Pointers to member functions
- File streams (`std::ifstream`, `std::ofstream`)
- `switch` statement

---

### ex00 — BraiiiiiiinnnzzzZ

**Goal:** Understand when to allocate objects on the stack vs the heap.

Implement a `Zombie` class with a private `name` attribute and an `announce()` member function. Then implement two functions:

- `Zombie* newZombie(std::string name)` — allocates a zombie on the heap and returns it.
- `void randomChump(std::string name)` — allocates a zombie on the stack and makes it announce itself.

The destructor prints the zombie's name for debugging.

**Files:**
| File | Description |
|---|---|
| `Zombie.hpp/.cpp` | Zombie class with `announce()` and destructor |
| `newZombie.cpp` | Creates and returns a heap-allocated zombie |
| `randomChump.cpp` | Creates a stack-allocated zombie that announces itself |
| `main.cpp` | Tests both functions |

---

### ex01 — Moar brainz!

**Goal:** Allocate multiple objects in a single heap allocation.

Implement `Zombie* zombieHorde(int N, std::string name)` which allocates `N` Zombie objects in a single `new[]` call, sets each one's name, and returns a pointer to the first.

> ⚠️ Must use `delete[]` to deallocate — check for memory leaks with valgrind.

**Files:**
| File | Description |
|---|---|
| `Zombie.hpp/.cpp` | Reused from ex00 |
| `zombieHorde.cpp` | Allocates and initializes the horde |
| `main.cpp` | Tests the horde with `announce()` on each zombie |

---

### ex02 — HI THIS IS BRAIN

**Goal:** Demystify references by comparing them to pointers.

Declare a `std::string` initialized to `"HI THIS IS BRAIN"`, a pointer to it (`stringPTR`), and a reference to it (`stringREF`). Print the memory addresses and values of all three.

**Files:**
| File | Description |
|---|---|
| `main.cpp` | Declares string, pointer, reference, and prints addresses and values |

---

### ex03 — Unnecessary violence

**Goal:** Decide when to use a reference vs a pointer to hold an object.

Implement a `Weapon` class with a private `type` string, `getType()` (returns `const std::string&`) and `setType()`. Then create:

- `HumanA` — always has a weapon; takes it by reference in the constructor.
- `HumanB` — may not have a weapon; stores it as a pointer, set via `setWeapon()`.

Both have an `attack()` member function that prints `<name> attacks with their <weapon type>`.

**Files:**
| File | Description |
|---|---|
| `Weapon.hpp/.cpp` | Weapon class |
| `HumanA.hpp/.cpp` | Always-armed human, holds weapon by reference |
| `HumanB.hpp/.cpp` | Optionally-armed human, holds weapon by pointer |
| `main.cpp` | Tests both humans with `setType()` in between attacks |

---

### ex04 — Sed is for losers

**Goal:** Work with file streams and string manipulation.

Takes three arguments: `filename`, `s1`, `s2`. Opens `<filename>`, reads its content, replaces every occurrence of `s1` with `s2` (without using `std::string::replace`), and writes the result to `<filename>.replace`.

> ⚠️ C file functions (`fopen`, `fread`, etc.) are forbidden.

**Files:**
| File | Description |
|---|---|
| `main.cpp` | Entry point, argument validation |
| `*.hpp/.cpp` | File reading, string replacement, file writing logic |

---

### ex05 — Harl 2.0

**Goal:** Use pointers to member functions to avoid if/else chains.

Implement a `Harl` class with four private methods (`debug`, `info`, `warning`, `error`) and a public `complain(std::string level)` method that dispatches to the correct one using an array of pointers to member functions — no `if/else if` allowed.

**Files:**
| File | Description |
|---|---|
| `Harl.hpp/.cpp` | Harl class with member function pointer dispatch |
| `main.cpp` | Tests all four complaint levels |

---

### ex06 — Harl filter

**Goal:** Use `switch` statements to filter log output by level.

A program `harlFilter` that takes a log level as argument and prints all messages from that level and above. If an unknown level is passed, it prints a default message.

**Example:**
```bash
./harlFilter "WARNING"
[ WARNING ]
I think I deserve to have some extra bacon for free. ...

[ ERROR ]
This is unacceptable! I want to speak to the manager now.
```

**Files:**
| File | Description |
|---|---|
| `Harl.hpp/.cpp` | Reused/adapted from ex05 |
| `main.cpp` | Reads level argument and uses `switch` to filter output |

</details>

---

## 🔧 How to Compile

Each exercise has its own `Makefile`. To compile:

```bash
cd cpp00/ex00
make
./megaphone "hello 42"
```

**Available rules:**
```bash
make        # compiles the project
make clean  # removes object files
make fclean # removes everything including the binary
make re     # fclean + make
```

---

## 📚 Concepts per Module (Roadmap)

| Module | Main Topic |
|---|---|
| [CPP00](CPP00) | Namespaces, Classes, I/O, Static |
| [CPP01](CPP01) | Memory, Pointers, References, `new`/`delete` |
| CPP02 | Orthodox Canonical Form, Operator Overloading |
| CPP03 | Inheritance |
| CPP04 | Polymorphism, Abstract Classes, Interfaces |
| CPP05 | Exceptions |
| CPP06 | C++ Casts |
| CPP07 | Templates |
| CPP08 | STL Containers and Iterators |
| CPP09 | STL Algorithms |

---
