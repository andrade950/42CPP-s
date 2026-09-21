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

CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98 -g
DEPFLAGS    = -MMD -MP
ASAN        = -fsanitize=address -fsanitize=undefined
NAME        = AForm

OBJ_DIR     = objs

SRCS        = main.cpp Bureaucrat.cpp AForm.cpp \
              ShrubberyCreationForm.cpp \
              RobotomyRequestForm.cpp \
              PresidentialPardonForm.cpp

OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPS        = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\n$(YELLOW)Arquivando múltiplos protocolos em $(NAME)...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "$(GREEN)Ministério em pleno funcionamento! $(NAME) pronto.$(RESET)\n"

# Objects depend on their headers through the generated .d files (-MMD),
# so editing a .hpp recompiles everything that includes it.
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@printf "$(CYAN)Processando subsetor:$(RESET) $(notdir $<)\n"
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	@printf "$(RED)Triturando documentos obsoletos (objetos)...$(RESET)\n"
	@rm -rf $(OBJ_DIR)
	@rm -f *_shrubbery

fclean: clean
	@printf "$(RED)Encerrando todos os departamentos (binário)...$(RESET)\n"
	@rm -f $(NAME)

re: fclean all

# --- Debug ---
va: all
	@printf "$(PURPLE)Valgrind...$(RESET)\n"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

asan: fclean
	@printf "$(PURPLE)AddressSanitizer...$(RESET)\n"
	@$(CC) $(CFLAGS) $(ASAN) $(SRCS) -o $(NAME)
	@./$(NAME)

-include $(DEPS)

.PHONY: all clean fclean re va asan

GREEN       = \033[1;32m
YELLOW      = \033[1;33m
RED         = \033[1;31m
CYAN        = \033[1;36m
PURPLE      = \033[1;35m
RESET       = \033[0m
