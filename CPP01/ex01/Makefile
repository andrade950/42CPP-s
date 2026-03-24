# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/17 13:59:58 by joaomart          #+#    #+#              #
#    Updated: 2026/03/17 14:24:50 by joaomart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Configurações ---
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -g
NAME		= Zombie

# --- Ficheiros ---
SRCS		= main.cpp Zombie.cpp zombieHorde.cpp
OBJS		= $(SRCS:.cpp=.o)

# --- Regras Principais ---
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(YELLOW)Infectando a população para criar $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)A horda de $(NAME)s está pronta! ☣️ 🧟🧟🧟$(RESET)"

%.o: %.cpp
	@echo "$(CYAN)Propagando vírus:$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# --- Limpeza ---
clean:
	@echo "$(RED)Eliminando vestígios biológicos (objetos)...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Quarentena total (binário)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

# --- Debug ---
# Verificação crucial para o 'zombieHorde' (uso de new[] e delete[])
va: all
	@echo "$(YELLOW)Inspecionando a horda no microscópio (Valgrind)...$(RESET)"
	@valgrind -q --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re va

# --- Cores ---
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
RED			= \033[1;31m
CYAN		= \033[1;36m
RESET		= \033[0m