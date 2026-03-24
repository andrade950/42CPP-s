# CPP's — Módulos de C++

[Read in English](README.md)

> Repositório com todos os exercícios dos módulos de C++ da 42.  
> Cada módulo introduz conceitos progressivos da linguagem — do básico ao avançado.

---

## 📁 Estrutura do Repositório

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

## 🗂️ Módulos

<details>
<summary><strong>CPP00 — Namespaces, Classes, I/O</strong></summary>

### Conceitos abordados
- Namespaces (`std::`)
- Classes, atributos e métodos
- Encapsulamento (`private` / `public`)
- Getters e Setters
- Variáveis e métodos estáticos
- Construtor e Destrutor
- `std::cin`, `std::cout`, `std::getline`

---

### ex00 — Megaphone

**Objectivo:** Introdução ao C++ e à utilização de `std::cout`.

O programa recebe palavras como argumentos e imprime-as em maiúsculas.  
Se não receber argumentos, imprime uma mensagem de ruído.

**Exemplo:**
```bash
./megaphone "hello world"
HELLO WORLD

./megaphone
* LOUD AND UNBEARABLE NOISE *
```

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `megaphone.cpp` | Lógica principal, percorre `argv[]` e converte com `std::toupper()` |

---

### ex01 — Phonebook

**Objectivo:** Introdução a classes e interacção com o utilizador.

Uma agenda com capacidade para 8 contactos. Quando cheia, o contacto mais antigo é substituído pelo novo.

**Comandos disponíveis:**
| Comando | Acção |
|---|---|
| `ADD` | Adiciona um novo contacto |
| `SEARCH` | Lista e pesquisa contactos por índice |
| `EXIT` | Termina o programa |

**Campos de cada contacto:** Primeiro nome, Apelido, Alcunha, Número de telefone, Segredo mais sombrio.

> ⚠️ Na tabela do SEARCH, nomes com mais de 10 caracteres são truncados com `.` — ex: `"JoaoMartins"` → `"JoaoMarti."`

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `main.cpp` | Ciclo principal, lê o input e cria contactos |
| `Contact.hpp/.cpp` | Classe com os dados de cada contacto |
| `Phonebook.hpp/.cpp` | Classe que gere o array de 8 contactos |
| `utils.hpp/.cpp` | Funções auxiliares: `Display()`, `IsNumber()`, `Stoi()`, `HandleSignal()` |

</details>

---

<details>
<summary><strong>CPP01 — Alocação de memória, ponteiros para membros, referências e switch</strong></summary>

### Conceitos abordados
- Stack vs heap (`new` / `delete`)
- Arrays de objectos no heap
- Ponteiros e referências
- Ponteiros para funções membro
- Streams de ficheiros (`std::ifstream`, `std::ofstream`)
- Instrução `switch`

---

### ex00 — BraiiiiiiinnnzzzZ

**Objectivo:** Perceber quando alocar objectos na stack vs no heap.

Implementar uma classe `Zombie` com atributo privado `name` e uma função membro `announce()`. Depois implementar duas funções:

- `Zombie* newZombie(std::string name)` — aloca um zombie no heap e retorna-o.
- `void randomChump(std::string name)` — aloca um zombie na stack e faz com que ele se anuncie.

O destrutor imprime o nome do zombie para fins de depuração.

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `Zombie.hpp/.cpp` | Classe Zombie com `announce()` e destrutor |
| `newZombie.cpp` | Cria e retorna um zombie alocado no heap |
| `randomChump.cpp` | Cria um zombie na stack que se anuncia |
| `main.cpp` | Testa ambas as funções |

---

### ex01 — Moar brainz!

**Objectivo:** Alocar múltiplos objectos numa única alocação no heap.

Implementar `Zombie* zombieHorde(int N, std::string name)` que aloca `N` objectos Zombie numa única chamada a `new[]`, inicializa o nome de cada um e retorna um ponteiro para o primeiro.

> ⚠️ É obrigatório usar `delete[]` para libertar a memória — verificar fugas com valgrind.

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `Zombie.hpp/.cpp` | Reutilizado do ex00 |
| `zombieHorde.cpp` | Aloca e inicializa a horda |
| `main.cpp` | Testa a horda chamando `announce()` em cada zombie |

---

### ex02 — HI THIS IS BRAIN

**Objectivo:** Desmistificar as referências comparando-as com ponteiros.

Declarar uma `std::string` inicializada com `"HI THIS IS BRAIN"`, um ponteiro para ela (`stringPTR`) e uma referência para ela (`stringREF`). Imprimir os endereços de memória e os valores dos três.

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `main.cpp` | Declara a string, o ponteiro e a referência, e imprime endereços e valores |

---

### ex03 — Unnecessary violence

**Objectivo:** Decidir quando usar referência vs ponteiro para guardar um objecto.

Implementar uma classe `Weapon` com atributo privado `type`, `getType()` (retorna `const std::string&`) e `setType()`. Depois criar:

- `HumanA` — sempre tem arma; recebe-a por referência no construtor.
- `HumanB` — pode não ter arma; guarda-a como ponteiro, definido via `setWeapon()`.

Ambos têm uma função membro `attack()` que imprime `<nome> attacks with their <tipo de arma>`.

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `Weapon.hpp/.cpp` | Classe Weapon |
| `HumanA.hpp/.cpp` | Humano sempre armado, guarda a arma por referência |
| `HumanB.hpp/.cpp` | Humano opcionalmente armado, guarda a arma por ponteiro |
| `main.cpp` | Testa ambos os humanos com `setType()` entre os ataques |

---

### ex04 — Sed is for losers

**Objectivo:** Trabalhar com streams de ficheiros e manipulação de strings.

Recebe três argumentos: `filename`, `s1`, `s2`. Abre `<filename>`, lê o seu conteúdo, substitui todas as ocorrências de `s1` por `s2` (sem usar `std::string::replace`), e escreve o resultado em `<filename>.replace`.

> ⚠️ Funções C de ficheiros (`fopen`, `fread`, etc.) são proibidas.

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `main.cpp` | Ponto de entrada, validação de argumentos |
| `*.hpp/.cpp` | Leitura do ficheiro, substituição de strings, escrita do ficheiro |

---

### ex05 — Harl 2.0

**Objectivo:** Usar ponteiros para funções membro para evitar cadeias de if/else.

Implementar uma classe `Harl` com quatro métodos privados (`debug`, `info`, `warning`, `error`) e um método público `complain(std::string level)` que despacha para o correcto usando um array de ponteiros para funções membro — sem `if/else if`.

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `Harl.hpp/.cpp` | Classe Harl com despacho por ponteiro para função membro |
| `main.cpp` | Testa os quatro níveis de reclamação |

---

### ex06 — Harl filter

**Objectivo:** Usar instruções `switch` para filtrar a saída por nível de log.

Um programa `harlFilter` que recebe um nível de log como argumento e imprime todas as mensagens desse nível para cima. Se um nível desconhecido for passado, imprime uma mensagem por omissão.

**Exemplo:**
```bash
./harlFilter "WARNING"
[ WARNING ]
I think I deserve to have some extra bacon for free. ...

[ ERROR ]
This is unacceptable! I want to speak to the manager now.
```

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `Harl.hpp/.cpp` | Reutilizado/adaptado do ex05 |
| `main.cpp` | Lê o argumento de nível e usa `switch` para filtrar a saída |

</details>

---

## 🔧 Como Compilar

Cada exercício tem o seu próprio `Makefile`. Para compilar:

```bash
cd cpp00/ex00
make
./megaphone "hello 42"
```

**Regras disponíveis:**
```bash
make        # compila o projecto
make clean  # remove os ficheiros objecto
make fclean # remove tudo, incluindo o binário
make re     # fclean + make
```

---

## 📚 Conceitos por Módulo (Roadmap)

| Módulo | Tema Principal |
|---|---|
| [CPP00](CPP00) | Namespaces, Classes, I/O, Estático |
| [CPP01](CPP01) | Memória, Ponteiros, Referências, `new`/`delete` |
| CPP02 | Forma Canónica Ortodoxa, Sobrecarga de Operadores |
| CPP03 | Herança |
| CPP04 | Polimorfismo, Classes Abstractas, Interfaces |
| CPP05 | Excepções |
| CPP06 | Casts em C++ |
| CPP07 | Templates |
| CPP08 | Contentores e Iteradores STL |
| CPP09 | Algoritmos STL |

---
