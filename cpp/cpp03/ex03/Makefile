NAME = diamondtrap

CXX = c++
CXXFLAG = -Wall -Werror -Wextra -std=c++98 -Wshadow -Wno-shadow
RM = rm -f

HEADER = -I .
HEADERS = ClapTrap.hpp ScavTrap.cpp FragTrap.hpp DiamondTrap.hpp

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

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