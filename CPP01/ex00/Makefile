# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/12 13:33:43 by joaomart          #+#    #+#              #
#    Updated: 2026/03/17 14:24:58 by joaomart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Configurações ---
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -g
NAME		= Zombie

# --- Ficheiros ---
SRCS		= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS		= $(SRCS:.cpp=.o)

# --- Regras Principais ---
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(YELLOW)Infectando ficheiros para criar $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Horda de $(NAME)s pronta para atacar! 🧟🧟$(RESET)"

%.o: %.cpp
	@echo "$(CYAN)Cultivando vírus:$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# --- Limpeza ---
clean:
	@echo "$(RED)Queimando cadáveres (objetos)...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Limpando o apocalipse (binário)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

# --- Debug ---
# Verificação de fugas (essencial para o 'newZombie' que usa 'new')
va: all
	@echo "$(YELLOW)Procurando zombies perdidos na memória (Valgrind)...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re va

# --- Cores ---
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
RED			= \033[1;31m
CYAN		= \033[1;36m
RESET		= \033[0m