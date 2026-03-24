# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/17 14:17:35 by joaomart          #+#    #+#              #
#    Updated: 2026/03/24 14:50:08 by joaomart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Configurações ---
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -g
NAME		= Violence

# --- Ficheiros ---
SRCS		= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJS		= $(SRCS:.cpp=.o)

# --- Regras Principais ---
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(YELLOW)Forjando armamento para $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Arsenal pronto! Que comece a $(NAME). ⚔️🛡️$(RESET)"

%.o: %.cpp
	@echo "$(CYAN)Treinando combatente:$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# --- Limpeza ---
clean:
	@echo "$(RED)Limpando o campo de batalha (objetos)...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Desarmando exército (binário)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

# --- Debug ---
# Essencial para garantir que o ponteiro do HumanB não explode!
va: all
	@echo "$(YELLOW)Inspecionando ferimentos de memória (Valgrind)...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re va

# --- Cores ---
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
RED			= \033[1;31m
CYAN		= \033[1;36m
RESET		= \033[0m
