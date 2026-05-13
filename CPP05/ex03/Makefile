# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/11 15:56:55 by joaomart          #+#    #+#              #
#    Updated: 2026/05/13 11:15:12 by joaomart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = Intern

# --- Compiler & Flags ---
CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98 -g
ASAN        = -fsanitize=address -fsanitize=leak -fsanitize=undefined

# --- Directories ---
OBJ_DIR     = obj

# --- Source Files ---
SRCS         = main.cpp Bureaucrat.cpp AForm.cpp Intern.cpp \
               ShrubberyCreationForm.cpp \
               RobotomyRequestForm.cpp \
               PresidentialPardonForm.cpp

# --- Objects ---
OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

# --- Rules ---

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(YELLOW)Compilando $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) pronto para uso!$(RESET)"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@printf "$(CYAN)Compilando: $(RESET)%-30s " "$<"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GREEN)[OK]$(RESET)\n"

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f *_shrubbery
	@echo "$(RED)Limpeza:$(RESET) Objetos e ficheiros temporários removidos."

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Limpeza Total:$(RESET) Executável $(NAME) removido."

re: fclean all

# --- Debug & Test Rules ---

# Corre com Valgrind para verificação de memória
va: all
	@echo "$(PURPLE)Iniciando auditoria de memória (Valgrind)...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

# Compila e corre com Address Sanitizer
asan: fclean
	@echo "$(PURPLE)Rastreando integridade (ASAN)...$(RESET)"
	@$(CC) $(CFLAGS) $(ASAN) $(SRCS) -o $(NAME)
	@./$(NAME)

.PHONY: all clean fclean re va asan

# --- Output Styling ---
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
RED         = \033[1;31m
CYAN        = \033[1;36m
PURPLE      = \033[1;35m
RESET       = \033[0m