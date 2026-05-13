# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/11 14:33:18 by joaomart          #+#    #+#              #
#    Updated: 2026/05/11 15:51:18 by joaomart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Configurações de Estado ---
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -g
NAME		= Form

# --- Documentação ---
SRCS		= main.cpp Bureaucrat.cpp Form.cpp
OBJS		= $(SRCS:.cpp=.o)

# --- Regras de Processamento ---
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(YELLOW)Carimbando e numerando formulários para $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Ministério do C++: $(NAME) está pronto para assinar! 🖋️📜$(RESET)"

%.o: %.cpp
	@echo "$(CYAN)Autenticando documento:$(RESET) $(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

# --- Gestão de Resíduos ---
clean:
	@echo "$(RED)Queimando evidências (objetos)...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Encerrando o departamento permanentemente (binário)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

# --- Auditoria Interna ---
# Verificação de fugas de memória no sistema de arquivos
va: all
	@echo "$(PURPLE)Auditoria Fiscal do Valgrind em curso...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

# Teste de Estresse de Segurança
asan: fclean
	@echo "$(PURPLE)Inspecionando integridade dos documentos (ASAN)...$(RESET)"
	@$(CC) $(CFLAGS) -fsanitize=address -fsanitize=leak -fsanitize=undefined $(SRCS) -o $(NAME)
	@./$(NAME)

.PHONY: all clean fclean re va asan

# --- Cores do Arquivo Nacional ---
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
RED			= \033[1;31m
CYAN		= \033[1;36m
PURPLE		= \033[1;35m
RESET		= \033[0m