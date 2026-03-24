# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/17 14:30:34 by joaomart          #+#    #+#              #
#    Updated: 2026/03/24 14:50:12 by joaomart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Configurações ---
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -g
NAME		= SedForLosers

# --- Ficheiros ---
SRCS		= main.cpp
OBJS		= $(SRCS:.cpp=.o)

# --- Regras Principais ---
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(YELLOW)Programando o substituto para $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Script compilado! Quem precisa de sed? 🛠️  🚫$(RESET)"

%.o: %.cpp
	@echo "$(CYAN)Escaneando código:$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# --- Limpeza ---
clean:
	@echo "$(RED)Limpando ficheiros temporários...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Removendo binário...$(RESET)"
	@rm -f $(NAME)
	@@rm -f *.replace
	@echo "$(RED)Ficheiros .replace apagados! 🧹$(RESET)"

re: fclean all

# --- Debug ---
# Útil para testar se não há leaks ao abrir/fechar ficheiros
va: all
	@echo "$(YELLOW)Verificando fugas de descritores e memória...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) test.txt "procurar" "substituir"

.PHONY: all clean fclean re va

# --- Cores ---
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
RED			= \033[1;31m
CYAN		= \033[1;36m
RESET		= \033[0m