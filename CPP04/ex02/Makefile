# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/13 15:27:06 by joaomart          #+#    #+#              #
#    Updated: 2026/04/21 15:42:39 by joaomart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Configurações ---
CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98 -g
NAME        = Brain

# --- Ficheiros ---
SRCS        = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJS        = $(SRCS:.cpp=.o)

# --- Regras Principais ---
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(YELLOW)Iniciando replicação neural para $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Rede neuronal e animais prontos! 🧠🐕🐈$(RESET)"

%.o: %.cpp
	@echo "$(CYAN)Mapeando sinapses:$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# --- Limpeza ---
clean:
	@echo "$(RED)Limpando resíduos biológicos (objetos)...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Resetando o laboratório (binário)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

# --- Debug ---
# Este comando é vital para confirmar que o delete[] do Brain funcionou 100 vezes!
va: all
	@echo "$(YELLOW)Analisando integridade da Deep Copy (Valgrind)...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re va

# --- Cores ---
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
RED			= \033[1;31m
CYAN		= \033[1;36m
MAGENTA		= \033[1;35m
RESET		= \033[0m