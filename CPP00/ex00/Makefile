NAME	= megaphone

CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -g

SRCS		= megaphone.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# --- Limpeza ---
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

va: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re va