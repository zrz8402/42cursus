NAME = test

CXX = c++
CXXFLAGS = -std=c++98
RM = rm -f

HEADERS = 
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(HEADERS) $(OBJS) -o $(NAME)

%.o: %.c Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean all