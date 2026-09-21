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

CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98 -g
DEPFLAGS    = -MMD -MP
ASAN        = -fsanitize=address -fsanitize=undefined
NAME        = Intern

OBJ_DIR     = objs

SRCS        = main.cpp Bureaucrat.cpp AForm.cpp Intern.cpp \
              ShrubberyCreationForm.cpp \
              RobotomyRequestForm.cpp \
              PresidentialPardonForm.cpp

OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPS        = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\n$(YELLOW)Compilando $(NAME)...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "$(GREEN)$(NAME) pronto para uso!$(RESET)\n"

# Objects depend on their headers through the generated .d files (-MMD),
# so editing a .hpp recompiles everything that includes it.
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@printf "$(CYAN)Compilando:$(RESET) $(notdir $<)\n"
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	@printf "$(RED)Limpeza: objetos e ficheiros temporários removidos.$(RESET)\n"
	@rm -rf $(OBJ_DIR)
	@rm -f *_shrubbery

fclean: clean
	@printf "$(RED)Limpeza total: executável removido.$(RESET)\n"
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
