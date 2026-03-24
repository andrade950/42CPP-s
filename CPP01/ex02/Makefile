# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/17 14:07:01 by joaomart          #+#    #+#              #
#    Updated: 2026/03/17 14:24:41 by joaomart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Configurações ---
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -g
NAME		= Brain

# --- Ficheiros ---
SRCS		= main.cpp
OBJS		= $(SRCS:.cpp=.o)

# --- Regras Principais ---
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(YELLOW)Estabelecendo sinapses para $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Consciência $(NAME) despertada! 🧠⚡$(RESET)"

%.o: %.cpp
	@echo "$(CYAN)Processando neurónio:$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# --- Limpeza ---
clean:
	@echo "$(RED)Apagando memórias curtas (objetos)...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Amnésia total (binário)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

# --- Debug ---
# Essencial para ver se os endereços de memória batem certo no output
va: all
	@echo "$(YELLOW)Mapeando atividade cerebral (Valgrind)...$(RESET)"
	@valgrind -q --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re va

# --- Cores ---
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
RED			= \033[1;31m
CYAN		= \033[1;36m
RESET		= \033[0m