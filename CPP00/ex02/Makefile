# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/11 14:19:25 by joaomart          #+#    #+#              #
#    Updated: 2026/03/12 10:17:11 by joaomart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Configurações ---
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -g
NAME		= Account

# --- Ficheiros ---
SRCS		= Account.cpp tests.cpp
OBJS		= $(SRCS:.cpp=.o)

# --- Regras Principais ---
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(YELLOW)Contabilizando transações para $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Cofre pronto! $(NAME) criado com sucesso. 💰🏦$(RESET)"

%.o: %.cpp
	@echo "$(CYAN)Processando extrato:$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# --- Limpeza ---
clean:
	@echo "$(RED)Queimando recibos (objetos)...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Fechando a conta (binário)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

# --- Debug ---
va: all
	@echo "$(YELLOW)Inspecionando fugas de capital com Valgrind...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

# Atalho para comparar logs (útil para este exercício específico)
diff: all
	@echo "$(CYAN)Gerando log de transações...$(RESET)"
	@./$(NAME) > my_account.log
	@echo "$(GREEN)Log guardado em 'my_account.log' 📑$(RESET)"

.PHONY: all clean fclean re va diff

# --- Cores ---
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
RED			= \033[1;31m
CYAN		= \033[1;36m
RESET		= \033[0m