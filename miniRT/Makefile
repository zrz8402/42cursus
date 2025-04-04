NAME = minirt

CC = cc
CFLAGS =
DEPFLAGS = -MMD -MP

RM = rm -rf
MKDIR = mkdir -p

# Library Paths
LIBMLX = ./lib/MLX42
MLX_A = $(LIBMLX)/build/libmlx42.a

# Include Directories
HEADERS = -I ./inc -I $(LIBMLX)

# Libraries to Link
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

# Source Directories
MAIN_DIR = src
RAY_INTERSECT_DIR = src

# Source Files
MAIN_FILES = main.c init.c ops.c
RAY_INTERSECT_FILES = ray.c intersect.c

# Combine Source Files
MAIN = $(addprefix $(MAIN_DIR)/, $(MAIN_FILES))
RAY_INTERSECT = $(addprefix $(RAY_INTERSECT_DIR)/, $(RAY_INTERSECT_FILES))

# All Source Files
SRCS = $(MAIN) $(RAY_INTERSECT)

# Object Files Directory
OBJ_DIR = obj

# Object Files
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Dependency Files
DEPS = $(OBJS:.o=.d)

# Default Target
all: $(NAME)

# Link Object Files and Libraries to Create Executable
$(NAME): $(OBJS) $(MLX_A)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(NAME) compiled successfully!"

# Build libft Library
$(MLX_A):
	@cmake $(LIBMLX) -B $(LIBMLX)/build > /dev/null 2>&1 && make -s -C $(LIBMLX)/build -j4 > /dev/null 2>&1

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
	@$(RM) $(LIBMLX)/build
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