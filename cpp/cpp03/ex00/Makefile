NAME = claptrap

CXX = c++
CXXFLAG = -Wall -Werror -Wextra -std=c++98
RM = rm -f

HEADER = -I .
HEADERS = ClapTrap.hpp

SRCS = main.cpp ClapTrap.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAG) $(HEADER) $(OBJS) -o $(NAME)

%.o: %.cpp Makefile $(HEADERS)
	$(CXX) $(CXXFLAG) $(HEADER) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean make

.PHONY: all clean fclean re