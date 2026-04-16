# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/23 15:19:45 by joaomart          #+#    #+#              #
#    Updated: 2026/03/24 14:50:27 by joaomart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Configurações ---
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -g
NAME		= Claptrap

# --- Ficheiros ---
SRCS		= main.cpp ClapTrap.cpp
OBJS		= $(SRCS:.cpp=.o)

# --- Regras Principais ---
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(YELLOW)Montando peças de metal do $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Atenção viajante! $(NAME) está online (e pronto para falhar)! 🤖⚡$(RESET)"

%.o: %.cpp
	@echo "$(CYAN)Instalando subrotina:$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# --- Limpeza ---
clean:
	@echo "$(RED)Reciclando sucata (objetos)...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Desmantelando o robô (binário)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

# --- Debug ---
# O Valgrind é como um diagnóstico de óleo para o ClapTrap
va: all
	@echo "$(YELLOW)Executando diagnóstico de sistema...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re va

# --- Cores ---
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
RED			= \033[1;31m
CYAN		= \033[1;36m
RESET		= \033[0m