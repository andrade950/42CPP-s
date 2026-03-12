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
│   ├── ex01/   → Phonebook
│   └── ex02/   → The Account Class
├── cpp01/
│   ├── ex00/   → ...
│   └── ...
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

---

### ex02 — The Account Class

**Goal:** Work with static variables, constructor/destructor and timestamps.

Simulates bank accounts with deposits and withdrawals. Maintains global statistics across all accounts simultaneously.

**Static variables** (shared across all accounts):
```
_nbAccounts         → total number of accounts created
_totalAmount        → sum of all balances
_totalNbDeposits    → total deposits made
_totalNbWithdrawals → total withdrawals made
```

**Output format (example):**
```
[20260312_101435] index:0;amount:42;created
[20260312_101435] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
[20260312_101435] index:0;p_amount:47;withdrawal:321;withdrawal:refused
[20260312_101435] index:0;amount:47;closed
```

**Files:**
| File | Description |
|---|---|
| `Account.hpp` | Class interface (provided by the subject) |
| `Account.cpp` | Implementation of all methods |
| `tests.cpp` | Tests provided by the subject |

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
| CPP01 | Memory, Pointers, References, `new`/`delete` |
| CPP02 | Orthodox Canonical Form, Operator Overloading |
| CPP03 | Inheritance |
| CPP04 | Polymorphism, Abstract Classes, Interfaces |
| CPP05 | Exceptions |
| CPP06 | C++ Casts |
| CPP07 | Templates |
| CPP08 | STL Containers and Iterators |
| CPP09 | STL Algorithms |

---
