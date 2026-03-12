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
│   ├── ex01/   → Phonebook
│   └── ex02/   → The Account Class
├── cpp01/
│   ├── ex00/   → ...
│   └── ...
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

---

### ex02 — The Account Class

**Objectivo:** Trabalhar com variáveis estáticas, construtor/destrutor e timestamps.

Simula contas bancárias com depósitos e levantamentos. Mantém estatísticas globais de todas as contas em simultâneo.

**Variáveis estáticas** (partilhadas por todas as contas):
```
_nbAccounts         → número total de contas criadas
_totalAmount        → soma de todos os saldos
_totalNbDeposits    → total de depósitos efectuados
_totalNbWithdrawals → total de levantamentos efectuados
```

**Formato do output (exemplo):**
```
[20260312_101435] index:0;amount:42;created
[20260312_101435] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
[20260312_101435] index:0;p_amount:47;withdrawal:321;withdrawal:refused
[20260312_101435] index:0;amount:47;closed
```

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `Account.hpp` | Interface da classe (fornecida pelo enunciado) |
| `Account.cpp` | Implementação de todos os métodos |
| `tests.cpp` | Testes fornecidos pelo enunciado |

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
| CPP01 | Memória, Ponteiros, Referências, `new`/`delete` |
| CPP02 | Forma Canónica Ortodoxa, Sobrecarga de Operadores |
| CPP03 | Herança |
| CPP04 | Polimorfismo, Classes Abstractas, Interfaces |
| CPP05 | Excepções |
| CPP06 | Casts em C++ |
| CPP07 | Templates |
| CPP08 | Contentores e Iteradores STL |
| CPP09 | Algoritmos STL |

---
