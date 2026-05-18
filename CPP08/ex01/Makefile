# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/18 14:24:46 by joaomart          #+#    #+#              #
#    Updated: 2026/05/18 14:31:47 by joaomart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Program Name ---
NAME        = Span

# --- Commands & Flags ---
CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98 -g
RM          = rm -rf

# --- Debug Flags ---
ASANFLAGS   = -fsanitize=address -fsanitize=leak -fsanitize=undefined -fno-omit-frame-pointer

# --- Sources & Objects ---
SRCS        = main.cpp Span.cpp
OBJ_DIR     = obj/
OBJS        = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

# --- Main Rules ---

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "╔════════════════════════════╗"
	@echo "║ ✅ $(NAME) Compiled!          ║"
	@echo "╚════════════════════════════╝"

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)🔧 Compiling: $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(RED)🗑️  Objects removed.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)🗑️  Executable removed.$(RESET)"

re: fclean all

# --- Test Rules ---

# Compile and run with AddressSanitizer
asan: CFLAGS += $(ASANFLAGS)
asan: re
	@echo "$(GREEN)🚀 Running with AddressSanitizer...$(RESET)"
	@./$(NAME)

# Run Valgrind on the current binary
va: all
	@echo "$(GREEN)🔍 Running Valgrind...$(RESET)"
	@valgrind -q --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re asan va

# --- Output Colors ---
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
RED         = \033[1;31m
RESET       = \033[0m