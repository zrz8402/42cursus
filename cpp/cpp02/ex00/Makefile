NAME = fixed

CXX = c++
CXXFLAG = -Wall -Wextra -Werror -std=c++98
RM = rm -f

HEADER = -I .

SRCS = main.cpp Fixed.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAG) $(HEADER) $(OBJS) -o $(NAME)

%.o: %.cpp Makefile Fixed.hpp
	$(CXX) $(CXXFLAG) $(HEADER) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re