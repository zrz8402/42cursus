NAME = program

CXX = c++
CXXFLAG = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAG) $(OBJS) -o $(NAME)

%.o: %.cpp Makefile
	$(CXX) $(CXXFLAG) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re