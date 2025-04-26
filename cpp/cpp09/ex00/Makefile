NAME = btc

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

DEPFLAGS = -MMD -MP

RM = rm -rf
MKDIR = mkdir -p

HEADERS = -I ./inc

SRC_DIR = src
SRC_FILES = main.cpp BitcoinExchange.cpp
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = obj
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(HEADERS) $(OBJS) -o $(NAME)
	@echo "$(NAME) compiled successfully!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(MKDIR) $(dir $@)
	@$(CXX) $(CXXFLAGS) $(HEADERS) $(DEPFLAGS) -c $< -o $@

$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	@echo "Object files, dependency files, and $(OBJ_DIR) removed!"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) removed!"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re