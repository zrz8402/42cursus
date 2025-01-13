NAME = animal

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rdf

I = inc
S = src
O = obj

INC = -I $(I)

SRCS = $(S)/main.cpp $(S)/AMateria.cpp $(S)/ICharacter.cpp $(S)/Ice.cpp $(S)/Cure.cpp

OBJS = $(SRCS:$(S)/%.cpp=$(O)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INC) $(OBJS) -o $(NAME)

$(O)/%.o: $(S)/%.cpp | $(O)
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

$(O):
	@mkdir -p $(O)

clean:
	$(RM) $(O)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re