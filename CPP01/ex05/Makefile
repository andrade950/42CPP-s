# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/17 14:38:43 by joaomart          #+#    #+#              #
#    Updated: 2026/03/17 14:40:42 by joaomart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Configurações ---
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
NAME		= harl

# --- Ficheiros ---
SRCS		= main.cpp Harl.cpp
OBJS		= $(SRCS:.cpp=.o)

# --- Regras Principais ---
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(YELLOW)A preparar os pulmões do $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) está pronto para reclamar! 📢💢$(RESET)"

%.o: %.cpp
	@echo "$(CYAN)Aumentando nível de irritação:$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# --- Limpeza ---
clean:
	@echo "$(RED)Acalmando o Harl (removendo objetos)...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Silenciando tudo (removendo binário)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

# --- Debug ---
# O Harl não perdoa erros de memória!
va: all
	@echo "$(YELLOW)Ouvindo as queixas do Valgrind...$(RESET)"
	@valgrind -q --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re va

# --- Cores ---
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
RED			= \033[1;31m
CYAN		= \033[1;36m
RESET		= \033[0m
