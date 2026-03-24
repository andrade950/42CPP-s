# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/17 14:40:03 by joaomart          #+#    #+#              #
#    Updated: 2026/03/17 14:40:36 by joaomart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Configurações ---
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -g
NAME		= harlFilter

# --- Ficheiros ---
SRCS		= main.cpp Harl.cpp
OBJS		= $(SRCS:.cpp=.o)

# --- Regras Principais ---
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(YELLOW)Instalando filtros em $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Filtro calibrado! $(NAME) pronto para ignorar o que não interessa. 🔍🚿$(RESET)"

%.o: %.cpp
	@echo "$(CYAN)Refinando mensagem:$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# --- Limpeza ---
clean:
	@echo "$(RED)Limpando resíduos (objetos)...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Desativando sistema de filtragem (binário)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

# --- Debug ---
# O filtro tem de ser estanque! Nada de leaks.
va: all
	@echo "$(YELLOW)Verificando fugas no sistema de filtragem...$(RESET)"
	@valgrind -q --leak-check=full --show-leak-kinds=all ./$(NAME) "WARNING"

.PHONY: all clean fclean re va

# --- Cores ---
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
RED			= \033[1;31m
CYAN		= \033[1;36m
RESET		= \033[0m