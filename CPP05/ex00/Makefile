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

CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98 -g
DEPFLAGS    = -MMD -MP
ASAN        = -fsanitize=address -fsanitize=undefined
NAME        = Bureaucrat

OBJ_DIR     = objs

SRCS        = main.cpp Bureaucrat.cpp

OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPS        = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\n$(YELLOW)Imprimindo formulários para $(NAME)...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "$(GREEN)Guichê aberto! $(NAME) está pronto para carimbar.$(RESET)\n"

# Objects depend on their headers through the generated .d files (-MMD),
# so editing a .hpp recompiles everything that includes it.
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@printf "$(CYAN)Preenchendo campo:$(RESET) $(notdir $<)\n"
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	@printf "$(RED)Triturando papelada antiga (objetos)...$(RESET)\n"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@printf "$(RED)Encerrando o departamento (binário)...$(RESET)\n"
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
