NAME	= SedForLosers

CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -g

SRCS		= main.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f *.replace

re: fclean all

va: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) test.txt "procurar" "substituir"

.PHONY: all clean fclean re va