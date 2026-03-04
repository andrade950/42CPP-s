# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/04 11:25:18 by joaomart          #+#    #+#              #
#    Updated: 2026/03/04 11:25:38 by joaomart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
NAME = megaphone
SRCS = megaphone.cpp
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g
OBJS = $(SRCS:.cpp=.o)


all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -fr *.o

fclean : clean
	rm -fr $(NAME)

re : fclean all

va : re
	valgrind --leak-check=full --show-leak-kinds=all ./phonebook

.PHONY : all fclean re va