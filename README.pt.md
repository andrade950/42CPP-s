# CPP's — Módulos C++

[Read in English](README.md)

> Repositório com todos os exercícios dos módulos C++ da 42.  
> Cada módulo introduz progressivamente novos conceitos da linguagem — desde o básico até tópicos avançados.

---

## 📁 Estrutura do Repositório

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
└── cpp04/
    ├── ex00/   → Polymorphism
    ├── ex01/   → I don't want to set the world on fire
    └── ex02/   → Abstract class
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

**Objetivo:** Introdução ao C++ e à utilização de `std::cout`.

O programa recebe palavras como argumentos e imprime-as em maiúsculas.  
Se não forem fornecidos argumentos, imprime uma mensagem de ruído.

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
| `megaphone.cpp` | Lógica principal, itera sobre `argv[]` e converte com `std::toupper()` |

---

### ex01 — Phonebook

**Objetivo:** Introdução a classes e interação com o utilizador.

Uma agenda telefónica com capacidade para 8 contactos. Quando estiver cheia, o contacto mais antigo é substituído pelo novo.

**Comandos disponíveis:**
| Comando | Ação |
|---|---|
| `ADD` | Adiciona um novo contacto |
| `SEARCH` | Lista e pesquisa contactos por índice |
| `EXIT` | Termina o programa |

**Campos do contacto:** Primeiro nome, Apelido, Alcunha, Número de telefone, Segredo mais sombrio.

> ⚠️ Na tabela do SEARCH, nomes com mais de 10 caracteres são truncados com `.` — ex: `"JoaoMartins"` → `"JoaoMarti."`

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `main.cpp` | Ciclo principal, lê input e cria contactos |
| `Contact.hpp/.cpp` | Classe que guarda os dados de cada contacto |
| `Phonebook.hpp/.cpp` | Classe que gere o array de 8 contactos |
| `utils.hpp/.cpp` | Funções auxiliares: `Display()`, `IsNumber()`, `Stoi()`, `HandleSignal()` |

</details>

---

<details>
<summary><strong>CPP01 — Alocação de memória, ponteiros para membros, referências e switch</strong></summary>

### Conceitos abordados
- Alocação em stack vs heap (`new` / `delete`)
- Arrays de objetos na heap
- Ponteiros e referências
- Ponteiros para funções membro
- Streams de ficheiros (`std::ifstream`, `std::ofstream`)
- Instrução `switch`

---

### ex00 — BraiiiiiiinnnzzzZ

**Objetivo:** Perceber quando alocar objetos na stack vs na heap.

Implementar uma classe `Zombie` com um atributo privado `name` e uma função membro `announce()`. Depois implementar duas funções:

- `Zombie* newZombie(std::string name)` — aloca um zombie na heap e retorna-o.
- `void randomChump(std::string name)` — aloca um zombie na stack e faz com que ele se anuncie.

O destrutor imprime o nome do zombie para efeitos de depuração.

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `Zombie.hpp/.cpp` | Classe Zombie com `announce()` e destrutor |
| `newZombie.cpp` | Cria e retorna um zombie alocado na heap |
| `randomChump.cpp` | Cria um zombie na stack que se anuncia |
| `main.cpp` | Testa as duas funções |

---

### ex01 — Moar brainz!

**Objetivo:** Alocar múltiplos objetos numa única alocação na heap.

Implementar `Zombie* zombieHorde(int N, std::string name)` que aloca `N` objetos Zombie numa única chamada a `new[]`, define o nome de cada um e retorna um ponteiro para o primeiro.

> ⚠️ É obrigatório usar `delete[]` para libertar memória — verificar fugas com valgrind.

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `Zombie.hpp/.cpp` | Reutilizado do ex00 |
| `zombieHorde.cpp` | Aloca e inicializa a horda |
| `main.cpp` | Testa a horda chamando `announce()` em cada zombie |

---

### ex02 — HI THIS IS BRAIN

**Objetivo:** Desmistificar as referências comparando-as com ponteiros.

Declarar uma `std::string` inicializada com `"HI THIS IS BRAIN"`, um ponteiro para ela (`stringPTR`) e uma referência para ela (`stringREF`). Imprimir os endereços de memória e os valores dos três.

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `main.cpp` | Declara a string, o ponteiro, a referência e imprime endereços e valores |

---

### ex03 — Unnecessary violence

**Objetivo:** Decidir quando usar uma referência vs um ponteiro para guardar um objeto.

Implementar uma classe `Weapon` com uma string privada `type`, `getType()` (retorna `const std::string&`) e `setType()`. Depois criar:

- `HumanA` — tem sempre uma arma; recebe-a por referência no construtor.
- `HumanB` — pode não ter arma; guarda-a como ponteiro, definido via `setWeapon()`.

Ambos têm uma função membro `attack()` que imprime `<nome> attacks with their <tipo de arma>`.

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `Weapon.hpp/.cpp` | Classe Weapon |
| `HumanA.hpp/.cpp` | Humano sempre armado, guarda a arma por referência |
| `HumanB.hpp/.cpp` | Humano opcionalmente armado, guarda a arma por ponteiro |
| `main.cpp` | Testa os dois humanos com `setType()` entre ataques |

---

### ex04 — Sed is for losers

**Objetivo:** Trabalhar com streams de ficheiros e manipulação de strings.

Recebe três argumentos: `filename`, `s1`, `s2`. Abre `<filename>`, lê o conteúdo, substitui todas as ocorrências de `s1` por `s2` (sem usar `std::string::replace`), e escreve o resultado em `<filename>.replace`.

> ⚠️ Funções C de ficheiros (`fopen`, `fread`, etc.) são proibidas.

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `main.cpp` | Ponto de entrada, validação de argumentos |
| `*.hpp/.cpp` | Leitura de ficheiro, substituição de string, escrita de ficheiro |

---

### ex05 — Harl 2.0

**Objetivo:** Usar ponteiros para funções membro para evitar cadeias de if/else.

Implementar uma classe `Harl` com quatro métodos privados (`debug`, `info`, `warning`, `error`) e um método público `complain(std::string level)` que despacha para o correto usando um array de ponteiros para funções membro — sem `if/else if`.

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `Harl.hpp/.cpp` | Classe Harl com despacho por ponteiro para função membro |
| `main.cpp` | Testa os quatro níveis de reclamação |

---

### ex06 — Harl filter

**Objetivo:** Usar instruções `switch` para filtrar output de logs por nível.

Um programa `harlFilter` que recebe um nível de log como argumento e imprime todas as mensagens desse nível para cima. Se for passado um nível desconhecido, imprime uma mensagem por defeito.

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
| `main.cpp` | Lê o argumento de nível e usa `switch` para filtrar o output |

</details>

---

<details>
<summary><strong>CPP02 — Forma Canónica Ortodoxa, Sobrecarga de Operadores, Números de vírgula fixa</strong></summary>

### Conceitos abordados
- Forma Canónica Ortodoxa (construtor por defeito, construtor de cópia, operador de atribuição por cópia, destrutor)
- Representação de números em vírgula fixa
- Sobrecarga de operadores (comparação, aritmética, incremento/decremento, inserção em stream)
- Funções membro estáticas
- Polimorfismo ad-hoc

---

### ex00 — My First Class in Orthodox Canonical Form

**Objetivo:** Introdução à Forma Canónica Ortodoxa e a números de vírgula fixa.

Implementar uma classe `Fixed` que representa um número de vírgula fixa com 8 bits fracionários. A classe guarda o valor internamente como inteiro, expondo apenas `getRawBits()` / `setRawBits()`.

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `Fixed.hpp` | Definição da classe com `_fixedPoint` privado e `_frac_bits = 8` estático |
| `Fixed.cpp` | Implementação dos quatro membros canónicos + `getRawBits` / `setRawBits` |
| `main.cpp` | Testa construção, cópia, atribuição e recuperação do valor bruto |

---

### ex01 — Towards a more useful fixed-point number class

**Objetivo:** Adicionar construtores para inteiro e float, além de funções de conversão.

Estende a classe `Fixed` com dois novos construtores e duas funções membro de conversão, permitindo representar valores reais. Também sobrecarrega `operator<<` para impressão fácil.

- `Fixed(const int)` — converte um inteiro para vírgula fixa com deslocamento de 8 bits para a esquerda.
- `Fixed(const float)` — converte um float usando `roundf`.
- `toInt()` — converte o valor de vírgula fixa de volta para inteiro.
- `toFloat()` — converte o valor de vírgula fixa de volta para float.

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `Fixed.hpp` | Cabeçalho atualizado com novos construtores e funções de conversão |
| `Fixed.cpp` | Implementação dos construtores int/float, `toInt`, `toFloat` e `operator<<` |
| `main.cpp` | Testa todos os construtores, conversões e output em stream |

---

### ex02 — Now we're talking

**Objetivo:** Sobrecarga completa de operadores — comparações, aritmética, incremento/decremento e min/max.

A versão final e mais completa da classe `Fixed`. Implementa o conjunto completo de operadores necessários para a usar como tipo numérico.

- **Comparação:** `>`, `<`, `>=`, `<=`, `==`, `!=`
- **Aritmética:** `+`, `-`, `*`, `/`
- **Incremento/Decremento:** `++` / `--` (pré e pós), incrementando pelo menor ε representável (1 bit bruto)
- **min/max estáticos:** quatro sobrecargas (referências const e não-const)

> ⚠️ Divisão por zero pode terminar o programa abruptamente.

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `Fixed.hpp` | Definição completa da classe com todas as declarações de operadores |
| `Fixed.cpp` | Implementação de todos os operadores e funções estáticas `min` / `max` |
| `main.cpp` | Testes abrangentes: main do enunciado, comparações, aritmética, incremento/decremento e min/max |

</details>

---

<details>
<summary><strong>CPP03 — Herança</strong></summary>

### Conceitos abordados
- Herança de classes (herança `public`)
- Encadeamento de construtores/destrutores (base construída primeiro, derivada destruída primeiro)
- Sobreposição de funções membro
- Atributos protegidos
- Herança múltipla
- Herança virtual (problema do diamante)

---

### ex00 — Aaaaand... OPEN!

**Objetivo:** Introdução a classes e funções membro.

Implementar uma classe `ClapTrap` com os seguintes atributos privados:

| Atributo | Valor por defeito |
|---|---|
| Nome | passado via construtor |
| Pontos de vida | 10 |
| Pontos de energia | 10 |
| Dano de ataque | 0 |

Funções membro públicas:
- `void attack(const std::string& target)` — reduz os PV do alvo pelo dano de ataque, custa 1 ponto de energia
- `void takeDamage(unsigned int amount)` — reduz os próprios PV em `amount`
- `void beRepaired(unsigned int amount)` — restaura PV em `amount`, custa 1 ponto de energia

> ⚠️ O ClapTrap não pode agir sem PV ou pontos de energia. Construtores e destrutores devem imprimir mensagens.

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `ClapTrap.hpp/.cpp` | Classe ClapTrap com todos os atributos e funções membro |
| `main.cpp` | Testes de ataque, dano e reparação |

---

### ex01 — Serena, my love!

**Objetivo:** Introdução à herança e ao encadeamento de construtores/destrutores.

Implementar uma classe `ScavTrap` que herda de `ClapTrap`. Os seus construtores, destrutor e `attack()` imprimem mensagens diferentes. Quando um `ScavTrap` é criado, o construtor de `ClapTrap` é chamado primeiro; a destruição ocorre na ordem inversa.

| Atributo | Valor |
|---|---|
| Pontos de vida | 100 |
| Pontos de energia | 50 |
| Dano de ataque | 20 |

Habilidade especial: `void guardGate()` — mostra uma mensagem a indicar que o ScavTrap entrou no modo Guardião.

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `ClapTrap.hpp/.cpp` | Classe base (atualizada com atributos protegidos) |
| `ScavTrap.hpp/.cpp` | Classe derivada com mensagens sobrepostas e `guardGate()` |
| `main.cpp` | Testes que mostram o encadeamento de construção/destruição |

---

### ex02 — Repetitive work

**Objetivo:** Praticar herança com uma segunda classe derivada.

Implementar uma classe `FragTrap` que também herda de `ClapTrap`. O encadeamento de construção/destruição deve ser demonstrado.

| Atributo | Valor |
|---|---|
| Pontos de vida | 100 |
| Pontos de energia | 100 |
| Dano de ataque | 30 |

Habilidade especial: `void highFivesGuys(void)` — mostra um pedido positivo de high-five na saída padrão.

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `ClapTrap.hpp/.cpp` | Classe base |
| `ScavTrap.hpp/.cpp` | Do ex01 |
| `FragTrap.hpp/.cpp` | Nova classe derivada com `highFivesGuys()` |
| `main.cpp` | Testes para ScavTrap e FragTrap |

</details>

---

<details>
<summary><strong>CPP04 — Polimorfismo de Subtipo, Classes Abstratas e Interfaces</strong></summary>

### Conceitos abordados
- Funções virtuais e polimorfismo em tempo de execução
- Destrutores virtuais
- Classes abstratas (funções puramente virtuais)
- Cópia profunda vs cópia superficial
- Gestão de objetos alocados na heap
- Classes puramente abstratas como interfaces

---

### ex00 — Polymorphism

**Objetivo:** Compreender funções virtuais e polimorfismo de subtipo.

Implementar uma classe base `Animal` com um atributo protegido `std::string type`. Derivar `Dog` e `Cat` a partir dela, cada uma inicializando o seu `type` adequadamente. Cada animal expõe:

- `virtual void makeSound()` — imprime o som adequado para cada classe derivada

Quando chamada através de um ponteiro para a classe base, `makeSound()` despacha para a implementação correta da classe derivada.

Também implementar `WrongAnimal` e `WrongCat` (sem `virtual`) para demonstrar o que acontece sem polimorfismo — o `WrongCat` acaba por imprimir o som do `WrongAnimal`.

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `Animal.hpp/.cpp` | Classe base com `makeSound()` virtual e destrutor virtual |
| `Dog.hpp/.cpp` | Classe derivada, type = "Dog", ladra |
| `Cat.hpp/.cpp` | Classe derivada, type = "Cat", mia |
| `WrongAnimal.hpp/.cpp` | Classe base sem funções virtuais |
| `WrongCat.hpp/.cpp` | Classe derivada para mostrar comportamento não-polimórfico |
| `main.cpp` | Testa o despacho polimórfico através de ponteiros `Animal*` |

---

### ex01 — I don't want to set the world on fire

**Objetivo:** Praticar cópia profunda e objetos membro alocados na heap.

Implementar uma classe `Brain` que contém um array de 100 `std::string` chamado `ideas`. Tanto `Dog` como `Cat` passam a ter um atributo privado `Brain*` — alocado com `new` no construtor e eliminado no destrutor.

Requisitos principais:
- Um array de `Animal*` é criado com metade `Dog` e metade `Cat`, e depois totalmente eliminado — verificando que o destrutor virtual chama a cadeia correta.
- As cópias de `Dog`/`Cat` devem ser **profundas**: duplicar o objeto `Brain`, não apenas copiar o ponteiro.

> ⚠️ Verificar fugas de memória com valgrind.

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `Brain.hpp/.cpp` | Classe Brain com o array `ideas[100]` |
| `Dog.hpp/.cpp` | Atualizado com `Brain*`, cópia profunda no construtor de cópia e atribuição |
| `Cat.hpp/.cpp` | Igual ao Dog |
| `main.cpp` | Teste de alocação/eliminação do array e verificação de cópia profunda |

---

### ex02 — Abstract class

**Objetivo:** Impedir a instanciação da classe base usando funções puramente virtuais.

Estender o exercício anterior tornando `Animal` (ou `AAnimal`) abstrata. A função `makeSound()` passa a ser puramente virtual (`= 0`), tornando impossível instanciar `Animal` diretamente, enquanto tudo o resto funciona como antes.

**Ficheiros:**
| Ficheiro | Descrição |
|---|---|
| `AAnimal.hpp/.cpp` | Classe base abstrata com `makeSound()` puramente virtual |
| `Dog.hpp/.cpp` | Classe derivada concreta |
| `Cat.hpp/.cpp` | Classe derivada concreta |
| `Brain.hpp/.cpp` | Inalterado do ex01 |
| `main.cpp` | Mesmos testes do ex01 — a instanciação direta de `AAnimal` não deve compilar |

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
make        # compila o projeto
make clean  # remove os ficheiros objeto
make fclean # remove tudo incluindo o binário
make re     # fclean + make
make va     # make + valgrind
```

---

## 📚 Conceitos por Módulo (Roteiro)

| Módulo | Tema Principal |
|---|---|
| [CPP00](CPP00) | Namespaces, Classes, I/O, Static |
| [CPP01](CPP01) | Memória, Ponteiros, Referências, `new`/`delete` |
| [CPP02](CPP02) | Forma Canónica Ortodoxa, Sobrecarga de Operadores |
| [CPP03](CPP03) | Herança |
| [CPP04](CPP04) | Polimorfismo, Classes Abstratas |
| CPP05 | Exceções |
| CPP06 | Casts em C++ |
| CPP07 | Templates |
| CPP08 | Contentores e Iteradores STL |
| CPP09 | Algoritmos STL |
