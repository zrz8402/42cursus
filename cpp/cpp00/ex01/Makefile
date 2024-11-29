NAME = phonebook

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++11
RM = rm -f

HEADERS = -I .
HEADER_FILES = Contact.hpp PhoneBook.hpp
SRCS = main.cpp Contact.cpp PhoneBook.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(HEADERS) $(OBJS) -o $(NAME)

%.o: %.cpp Makefile $(HEADER_FILES)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re