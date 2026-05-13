# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/11 14:33:18 by joaomart          #+#    #+#              #
#    Updated: 2026/05/13 11:15:00 by Gemini            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Configurações de Protocolo ---
CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98 -g
NAME        = AForm

# --- Diretórios ---
OBJ_DIR     = objs

# --- Arquivos do Departamento ---
SRCS        = main.cpp Bureaucrat.cpp AForm.cpp \
              ShrubberyCreationForm.cpp \
              RobotomyRequestForm.cpp \
              PresidentialPardonForm.cpp

# Transforma a lista de SRCS em caminhos dentro da pasta OBJ_DIR
OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

# --- Processamento de Requerimentos ---
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(YELLOW)Arquivando múltiplos protocolos em $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Ministério em pleno funcionamento! $(NAME) pronto. 🏛️📂✨$(RESET)"

# Regra para compilar os .o dentro da pasta objs/
# O comando 'mkdir -p' garante que a pasta existe sem dar erro se já existir
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(CYAN)Processando subsetor:$(RESET) $(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

# --- Limpeza de Registos ---
clean:
	@echo "$(RED)Triturando documentos obsoletos (objetos)...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@rm -f *_shrubbery

fclean: clean
	@echo "$(RED)Encerrando todos os departamentos (binário)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

# --- Auditoria e Inspeção ---
va: all
	@echo "$(PURPLE)Iniciando auditoria de memória obrigatória...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

asan: fclean
	@echo "$(PURPLE)Rastreando integridade de sub-formulários (ASAN)...$(RESET)"
	@$(CC) $(CFLAGS) -fsanitize=address -fsanitize=leak -fsanitize=undefined $(SRCS) -o $(NAME)
	@./$(NAME)

.PHONY: all clean fclean re va asan

# --- Cores do Arquivo Nacional ---
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
RED         = \033[1;31m
CYAN        = \033[1;36m
PURPLE      = \033[1;35m
RESET       = \033[0m