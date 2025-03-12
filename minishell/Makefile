NAME = minishell

CC = cc
CFLAGS = 
DEPFLAGS = -MMD -MP

RM = rm -rf
MKDIR = mkdir -p

# Library Paths
LIBFT_PATH = ./lib/libft
LIBFT_A = $(LIBFT_PATH)/libft.a

# Include Directories
HEADERS = -I ./inc -I $(LIBFT_PATH)

# Libraries to Link
LIBS = -lreadline $(LIBFT_A)

# Source Directories
MAIN_DIR = src
SIG_DIR = src/signal
PARSE_DIR = 
EXEC_DIR = src/exec
BUILTIN_DIR = src/builtin

# Source Files
MAIN_FILES = main.c init.c utils.c
SIG_FILES = signal.c
PARSE_FILES = 
EXEC_FILES = process.c redir.c execute.c builtin.c cleanup.c
BUILTIN_FILES = env.c unset.c cd.c echo.c exit.c export.c pwd.c merge_sort.c

# Combine Source Files
MAIN = $(addprefix $(MAIN_DIR)/, $(MAIN_FILES))
SIG = $(addprefix $(SIG_DIR)/, $(SIG_FILES))
PARSE = $(addprefix $(PARSE_DIR)/, $(PARSE_FILES))
EXEC = $(addprefix $(EXEC_DIR)/, $(EXEC_FILES))
BUILTIN = $(addprefix $(BUILTIN_DIR)/, $(BUILTIN_FILES))

# All Source Files
SRCS = $(MAIN) $(SIG) $(PARSE) $(EXEC) $(BUILTIN)

# Object Files Directory
OBJ_DIR = obj

# Object Files
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Dependency Files
DEPS = $(OBJS:.o=.d)

# Default Target
all: $(NAME)

# Link Object Files and Libraries to Create Executable
$(NAME): $(OBJS) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(NAME) compiled successfully!"

# Build libft Library
$(LIBFT_A):
	@make -s -C $(LIBFT_PATH)

# Compile Source Files into Object Files
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(HEADERS) -c $< -o $@

# Create Object Directory
$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

# Clean Object Files and Dependency Files
clean:
	@$(RM) $(OBJ_DIR)
	@make fclean -s -C $(LIBFT_PATH)
	@echo "Object files, dependency files, and $(OBJ_DIR) removed!"

# Clean Everything (Object Files and Executable)
fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) removed!"

# Rebuild Project
re: fclean all

# Include Dependency Files
-include $(DEPS)

# Phony Targets
.PHONY: all clean fclean re