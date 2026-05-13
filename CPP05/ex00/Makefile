# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/30 11:57:14 by joaomart          #+#    #+#              #
#    Updated: 2026/05/11 14:30:58 by joaomart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Configurações de Protocolo ---
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -g
NAME		= Bureaucrat

# --- Arquivo de Registos ---
SRCS		= main.cpp Bureaucrat.cpp
OBJS		= $(SRCS:.cpp=.o)

# --- Regras de Atendimento ---
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(YELLOW)Imprimindo formulários para $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Guiché aberto! $(NAME) está pronto para carimbar. 📝☕$(RESET)"

%.o: %.cpp
	@echo "$(CYAN)Preenchendo campo:$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# --- Limpeza de Arquivo ---
clean:
	@echo "$(RED)Triturando papelada antiga (objetos)...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Encerrando o departamento (binário)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

# --- Auditoria (Debug) ---
# Auditoria de memória - Porque um burocrata não admite falhas!
va: all
	@echo "$(MAGENTA)Iniciando auditoria fiscal (Valgrind)...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

# Auditoria Sanitária (Address Sanitizer)
asan: fclean
	@echo "$(MAGENTA)Verificando contaminação de memória (ASAN)...$(RESET)"
	@$(CC) $(CFLAGS) -fsanitize=address -fsanitize=leak -fsanitize=undefined $(SRCS) -o $(NAME)
	@./$(NAME)

.PHONY: all clean fclean re va asan

# --- Cores (O código de cores do Ministério) ---
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
RED			= \033[1;31m
CYAN		= \033[1;36m
MAGENTA		= \033[1;35m
RESET		= \033[0m