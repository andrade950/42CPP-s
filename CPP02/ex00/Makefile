# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/17 14:59:21 by joaomart          #+#    #+#              #
#    Updated: 2026/03/24 14:50:42 by joaomart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Configurações ---
CC			= c++
# Mantendo o -Weffc++ que adicionaste, muito bem!
CFLAGS		= -Wall -Wextra -Werror -Weffc++ -std=c++98 -g
NAME		= Fixed

# --- Ficheiros ---
SRCS		= main.cpp Fixed.cpp
OBJS		= $(SRCS:.cpp=.o)

# --- Regras Principais ---
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(YELLOW)Calibrando pontos decimais em $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Sistema $(NAME) estabilizado! 🎯⚙️$(RESET)"

%.o: %.cpp
	@echo "$(CYAN)Ajustando bits:$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# --- Limpeza ---
clean:
	@echo "$(RED)Limpando resíduos de cálculo (objetos)...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Fazendo reset ao sistema (binário)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

# --- Debug ---
va: all
	@echo "$(YELLOW)Verificando integridade da memória...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re va

# --- Cores ---
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
RED			= \033[1;31m
CYAN		= \033[1;36m
RESET		= \033[0m