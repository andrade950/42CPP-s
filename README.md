# CPP's — C++ Modules

[Leia em Português](README_pt.md)

> Repository containing all exercises from the 42 C++ modules.  
> Each module progressively introduces new concepts of the language — from the basics to advanced topics.

---

## 📁 Repository Structure

```
cpp's/
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
├── cpp02/
│   ├── ex00/   → My First Class in Orthodox Canonical Form
│   ├── ex01/   → Towards a more useful fixed-point number class
│   └── ex02/   → Now we're talking
├── cpp03/
│   ├── ex00/   → Aaaaand... OPEN!
│   ├── ex01/   → Serena, my love!
│   └── ex02/   → Repetitive work
├── cpp04/
│   ├── ex00/   → Polymorphism
│   ├── ex01/   → I don't want to set the world on fire
│   └── ex02/   → Abstract class
└── cpp05/
    ├── ex00/   → Mommy, when I grow up, I want to be a bureaucrat!
    ├── ex01/   → Form up, maggots!
    ├── ex02/   → No, you need form 28B, not 28C...
    └── ex03/   → At least this beats coffee-making
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

<details>
<summary><strong>CPP02 — Orthodox Canonical Form, Operator Overloading, Fixed-point numbers</strong></summary>

### Concepts covered
- Orthodox Canonical Form (default constructor, copy constructor, copy assignment operator, destructor)
- Fixed-point number representation
- Operator overloading (comparison, arithmetic, increment/decrement, stream insertion)
- Static member functions
- Ad-hoc polymorphism

---

### ex00 — My First Class in Orthodox Canonical Form

**Goal:** Introduction to the Orthodox Canonical Form and fixed-point numbers.

Implement a `Fixed` class representing a fixed-point number with 8 fractional bits. The class stores its value as a raw integer internally, and only exposes `getRawBits()` / `setRawBits()` at this stage.

**Files:**
| File | Description |
|---|---|
| `Fixed.hpp` | Class definition with private `_fixedPoint` and static `_frac_bits = 8` |
| `Fixed.cpp` | Implementation of the four canonical members + `getRawBits` / `setRawBits` |
| `main.cpp` | Tests construction, copy, assignment and raw value retrieval |

---

### ex01 — Towards a more useful fixed-point number class

**Goal:** Add integer and float constructors plus conversion functions.

Extends the `Fixed` class with two new constructors and two conversion member functions, making it possible to actually represent real values. Also overloads `operator<<` for easy printing.

- `Fixed(const int)` — converts an integer to fixed-point by left-shifting 8 bits.
- `Fixed(const float)` — converts a float using `roundf`.
- `toInt()` — converts the fixed-point value back to an integer.
- `toFloat()` — converts the fixed-point value back to a float.

**Files:**
| File | Description |
|---|---|
| `Fixed.hpp` | Updated header with new constructors and conversion functions |
| `Fixed.cpp` | Implementation of int/float constructors, `toInt`, `toFloat`, and `operator<<` |
| `main.cpp` | Tests all constructors, conversions and stream output |

---

### ex02 — Now we're talking

**Goal:** Full operator overloading — comparisons, arithmetic, increment/decrement and min/max.

The final and most complete version of the `Fixed` class. Implements the full set of operators needed to use it as a proper numeric type.

- **Comparison:** `>`, `<`, `>=`, `<=`, `==`, `!=`
- **Arithmetic:** `+`, `-`, `*`, `/`
- **Increment/Decrement:** `++` / `--` (both pre and post), incrementing by the smallest representable ε (1 raw bit)
- **Static min/max:** four overloads (const and non-const references)

> ⚠️ Division by zero is acceptable to crash the program.

**Files:**
| File | Description |
|---|---|
| `Fixed.hpp` | Full class definition with all operator declarations |
| `Fixed.cpp` | Implementation of all operators and static `min` / `max` functions |
| `main.cpp` | Comprehensive tests: subject main, comparisons, arithmetic, increment/decrement and min/max |

</details>

---

<details>
<summary><strong>CPP03 — Inheritance</strong></summary>

### Concepts covered
- Class inheritance (`public` inheritance)
- Constructor/destructor chaining (base constructed first, derived destroyed first)
- Member function overriding
- Protected attributes
- Multiple inheritance
- Virtual inheritance (diamond problem)

---

### ex00 — Aaaaand... OPEN!

**Goal:** Introduction to classes and member functions.

Implement a `ClapTrap` class with the following private attributes:

| Attribute | Default value |
|---|---|
| Name | passed via constructor |
| Hit points | 10 |
| Energy points | 10 |
| Attack damage | 0 |

Public member functions:
- `void attack(const std::string& target)` — reduces target's HP by attack damage, costs 1 energy point
- `void takeDamage(unsigned int amount)` — reduces own HP by amount
- `void beRepaired(unsigned int amount)` — restores HP by amount, costs 1 energy point

> ⚠️ ClapTrap can't act if it has no HP or energy points left. Constructors and destructors must print messages.

**Files:**
| File | Description |
|---|---|
| `ClapTrap.hpp/.cpp` | ClapTrap class with all attributes and member functions |
| `main.cpp` | Tests for attack, damage and repair |

---

### ex01 — Serena, my love!

**Goal:** Introduction to inheritance and constructor/destructor chaining.

Implement a `ScavTrap` class that inherits from `ClapTrap`. Its constructors, destructor and `attack()` print different messages. When a `ScavTrap` is created, the `ClapTrap` constructor runs first; destruction happens in reverse.

| Attribute | Value |
|---|---|
| Hit points | 100 |
| Energy points | 50 |
| Attack damage | 20 |

Special ability: `void guardGate()` — displays a message that ScavTrap is now in Gatekeeper mode.

**Files:**
| File | Description |
|---|---|
| `ClapTrap.hpp/.cpp` | Base class (updated with protected attributes) |
| `ScavTrap.hpp/.cpp` | Derived class with overridden messages and `guardGate()` |
| `main.cpp` | Tests showing construction/destruction chaining |

---

### ex02 — Repetitive work

**Goal:** Practice inheritance with a second derived class.

Implement a `FragTrap` class that also inherits from `ClapTrap`. Construction/destruction chaining must be shown.

| Attribute | Value |
|---|---|
| Hit points | 100 |
| Energy points | 100 |
| Attack damage | 30 |

Special ability: `void highFivesGuys(void)` — displays a positive high-fives request on standard output.

**Files:**
| File | Description |
|---|---|
| `ClapTrap.hpp/.cpp` | Base class |
| `ScavTrap.hpp/.cpp` | From ex01 |
| `FragTrap.hpp/.cpp` | New derived class with `highFivesGuys()` |
| `main.cpp` | Tests for both ScavTrap and FragTrap |

</details>

---

<details>
<summary><strong>CPP04 — Subtype Polymorphism, Abstract Classes, Interfaces</strong></summary>

### Concepts covered
- Virtual functions and runtime polymorphism
- Virtual destructors
- Abstract classes (pure virtual functions)
- Deep copy vs shallow copy
- Heap-allocated objects and memory management
- Pure abstract classes as interfaces

---

### ex00 — Polymorphism

**Goal:** Understand virtual functions and subtype polymorphism.

Implement a base class `Animal` with a protected `std::string type` attribute. Derive `Dog` and `Cat` from it, each initializing their `type` accordingly. Every animal exposes:

- `virtual void makeSound()` — prints the appropriate sound for each derived class

When called through a base-class pointer, `makeSound()` dispatches to the correct derived implementation.

Also implement `WrongAnimal` and `WrongCat` (without `virtual`) to demonstrate what happens without polymorphism — `WrongCat` ends up printing `WrongAnimal`'s sound.

**Files:**
| File | Description |
|---|---|
| `Animal.hpp/.cpp` | Base class with virtual `makeSound()` and virtual destructor |
| `Dog.hpp/.cpp` | Derived class, type = "Dog", barks |
| `Cat.hpp/.cpp` | Derived class, type = "Cat", meows |
| `WrongAnimal.hpp/.cpp` | Base class without virtual functions |
| `WrongCat.hpp/.cpp` | Derived class to show non-polymorphic behaviour |
| `main.cpp` | Tests polymorphic dispatch via `Animal*` pointers |

---

### ex01 — I don't want to set the world on fire

**Goal:** Practice deep copy and heap-allocated member objects.

Implement a `Brain` class containing an array of 100 `std::string` called `ideas`. Both `Dog` and `Cat` gain a private `Brain*` attribute — allocated with `new` in the constructor and deleted in the destructor.

Key requirements:
- An array of `Animal*` is created with half `Dog` and half `Cat`, then fully deleted — verifying that the virtual destructor calls the correct chain.
- Copies of `Dog`/`Cat` must be **deep**: duplicating the `Brain` object, not just copying the pointer.

> ⚠️ Check for memory leaks with valgrind.

**Files:**
| File | Description |
|---|---|
| `Brain.hpp/.cpp` | Brain class with `ideas[100]` array |
| `Dog.hpp/.cpp` | Updated with `Brain*`, deep copy in copy constructor and assignment |
| `Cat.hpp/.cpp` | Same as Dog |
| `main.cpp` | Array allocation/deletion test and deep copy verification |

---

### ex02 — Abstract class

**Goal:** Prevent instantiation of the base class using pure virtual functions.

Extend the previous exercise by making `Animal` (or `AAnimal`) abstract. The `makeSound()` function becomes pure virtual (`= 0`), so it's impossible to instantiate `Animal` directly while everything else works as before.

**Files:**
| File | Description |
|---|---|
| `AAnimal.hpp/.cpp` | Abstract base class with pure virtual `makeSound()` |
| `Dog.hpp/.cpp` | Concrete derived class |
| `Cat.hpp/.cpp` | Concrete derived class |
| `Brain.hpp/.cpp` | Unchanged from ex01 |
| `main.cpp` | Same tests as ex01 — direct `AAnimal` instantiation must not compile |

</details>

---

<details>
<summary><strong>CPP05 — Repetition and Exceptions</strong></summary>

### Concepts covered
- Exceptions: `try` / `catch` / `throw`
- Custom exception classes nested in each class, derived from `std::exception` and overriding `what()`
- Exception safety: validate **before** modifying, so a failed call leaves the object untouched
- Orthodox Canonical Form with `const` attributes (name and grades can't be reassigned, only mutable state is copied)
- Abstract classes and pure virtual functions
- Public `execute()` in the base class checks the permissions, then calls a protected pure virtual `action()` (one single place for the checks)
- Table of function pointers instead of an `if / else if` chain
- Grades work backwards: **1 is the highest grade, 150 the lowest**

> ⚠️ Exception classes don't need to follow the Orthodox Canonical Form, but every other class does. No function bodies in headers (exception `what()` included) and no STL containers until CPP08.

---

### ex00 — Mommy, when I grow up, I want to be a bureaucrat!

**Goal:** Introduction to exceptions with the smallest cog of the machine.

A `Bureaucrat` has a **constant name** and a grade from `1` to `150`. Building one with an invalid grade throws `Bureaucrat::GradeTooHighException` (grade < 1) or `Bureaucrat::GradeTooLowException` (grade > 150).

- `getName()` / `getGrade()` — getters.
- `incrementBureaucrat()` — promotes (grade `3` → `2`); throws if it would go past `1`.
- `decrementBureaucrat()` — demotes; throws if it would go past `150`.
- `operator<<` prints `<name>, bureaucrat grade <grade>`.

> A failed increment/decrement leaves the grade unchanged.

**Example:**
```
Alice, bureaucrat grade 42
```

**Files:**
| File | Description |
|---|---|
| `Bureaucrat.hpp/.cpp` | Bureaucrat class and its two exception classes |
| `main.cpp` | Constructor limits, canonical form, promote/demote until it throws, exception catching, scope destruction |

---

### ex01 — Form up, maggots!

**Goal:** Make two classes collaborate and report failures through exceptions.

A `Form` has a constant name, a `signed` flag (false at construction), a constant grade to sign and a constant grade to execute — all **private**. Invalid grades throw `Form::GradeTooHighException` / `Form::GradeTooLowException`.

- `Form::beSigned(const Bureaucrat &)` — signs the form if the bureaucrat's grade is high enough, otherwise throws `Form::GradeTooLowException`.
- `Bureaucrat::signForm(Form &)` — calls `beSigned()` and reports:
  - `<bureaucrat> signed <form>`
  - `<bureaucrat> couldn't sign <form> because <reason>`
- `operator<<` prints all the form's information.

**Files:**
| File | Description |
|---|---|
| `Bureaucrat.hpp/.cpp` | Bureaucrat from ex00 + `signForm()` |
| `Form.hpp/.cpp` | Form class with `beSigned()` and its exceptions |
| `main.cpp` | Copy/assignment, promotion until the form can be signed, invalid grades, scope, several bureaucrats on the same form |

---

### ex02 — No, you need form 28B, not 28C...

**Goal:** Abstract base class and polymorphic forms that actually do something.

`Form` becomes the abstract class `AForm`. Its attributes stay private in the base class. The public `execute(const Bureaucrat &) const` checks that the form is signed and that the executor's grade is high enough (throwing `FormNotSignedException` / `GradeTooLowException` otherwise), then calls the protected pure virtual `action()`, which each concrete form implements.

| Form | Sign | Exec | Action |
|---|---|---|---|
| `ShrubberyCreationForm` | 145 | 137 | Creates `<target>_shrubbery` in the working directory with ASCII trees |
| `RobotomyRequestForm` | 72 | 45 | Drilling noises, then `<target>` is robotomized successfully 50% of the time, otherwise the robotomy fails |
| `PresidentialPardonForm` | 25 | 5 | `<target>` has been pardoned by Zaphod Beeblebrox |

All of them take a single constructor parameter: the target.

`Bureaucrat::executeForm(const AForm &) const` runs the form and prints `<bureaucrat> executed <form>`, or an explicit error message.

**Files:**
| File | Description |
|---|---|
| `Bureaucrat.hpp/.cpp` | Bureaucrat with `signForm()` and `executeForm()` |
| `AForm.hpp/.cpp` | Abstract base class with `beSigned()`, `execute()` and pure virtual `action()` |
| `ShrubberyCreationForm.hpp/.cpp` | Writes the ASCII trees to `<target>_shrubbery` |
| `RobotomyRequestForm.hpp/.cpp` | 50% success using `std::rand()` (seeded once per run) |
| `PresidentialPardonForm.hpp/.cpp` | Pardon message |
| `main.cpp` | Polymorphic array of `AForm*`, robotomy probability, file creation, signing/execution grade limits |

---

### ex03 — At least this beats coffee-making

**Goal:** Build objects from a name without an `if / else if` chain.

An `Intern` has no name, no grade and no state. Its `makeForm(name, target)` returns a `new` `AForm*` matching the name, prints `Intern creates <form>`, or prints an explicit error and throws `Intern::FormCreationException` when the name is unknown. The name lookup uses a table of names paired with a table of function pointers.

| Form name | Creates |
|---|---|
| `shrubbery creation` | `ShrubberyCreationForm` |
| `robotomy request` | `RobotomyRequestForm` |
| `presidential pardon` | `PresidentialPardonForm` |

Names are matched exactly (case-sensitive). The caller owns the returned pointer and must `delete` it.

```cpp
Intern  someRandomIntern;
AForm  *rrf = someRandomIntern.makeForm("robotomy request", "Bender");
delete rrf;
```

**Files:**
| File | Description |
|---|---|
| `Intern.hpp/.cpp` | Intern with `makeForm()`, factory functions kept in the `.cpp` |
| `Bureaucrat`, `AForm` and the three forms | Reused from ex02 |
| `main.cpp` | Valid and invalid names, edge cases (empty string, wrong case, extra spaces), sign and execute with different grades |

---

### Build & run

```bash
cd cpp05/ex03
make
./Intern
```

| Exercise | Binary |
|---|---|
| ex00 | `./Bureaucrat` |
| ex01 | `./Form` |
| ex02 | `./AForm` |
| ex03 | `./Intern` |

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
make va     # make + valgrind
make asan   # (cpp05) rebuild with AddressSanitizer + UBSan and run
```

> In `cpp05/ex02` and `cpp05/ex03`, `make clean` also removes the generated `*_shrubbery` files.

---

## 📚 Concepts per Module (Roadmap)

| Module | Main Topic |
|---|---|
| [CPP00](cpp00) | Namespaces, Classes, I/O, Static |
| [CPP01](cpp01) | Memory, Pointers, References, `new`/`delete` |
| [CPP02](cpp02) | Orthodox Canonical Form, Operator Overloading |
| [CPP03](cpp03) | Inheritance |
| [CPP04](cpp04) | Polymorphism, Abstract Classes |
| [CPP05](cpp05) | Exceptions, Abstract Classes, Function-pointer dispatch |
| CPP06 | C++ Casts |
| CPP07 | Templates |
| CPP08 | STL Containers and Iterators |
| CPP09 | STL Algorithms |
