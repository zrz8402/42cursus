NAME = webserv

CXX = c++
CXXFLAGS = -std=c++98 -pedantic
DEPFLAGS = -MMD -MP

RM = rm -rf
MKDIR = mkdir -p

DEBUG ?= 0
ifeq ($(DEBUG), 1)
    CXXFLAGS += -DDEBUG
endif

HEADERS = -I ./inc

MAIN_DIR = srcs
MAIN_FILES = main.cpp \
			ServerConfig.cpp ServerConfigUtils.cpp \
			Server.cpp \
			Router.cpp \
			Request.cpp \
			Response.cpp \
			Logger.cpp

MAIN = $(addprefix $(MAIN_DIR)/, $(MAIN_FILES))
SRCS = $(MAIN)

OBJ_DIR = obj
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) compiled successfully!"

$(OBJ_DIR)/%.o: %.cpp Makefile | $(OBJ_DIR)
	@$(MKDIR) $(dir $@)
	@$(CXX) $(CXXFLAGS) $(DEPFLAGS) $(HEADERS) -c $< -o $@

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
