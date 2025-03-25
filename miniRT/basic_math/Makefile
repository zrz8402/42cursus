NAME = math

CC = cc
CFLAGS = -Wall -Werror -Wextra
DEPFLAGS = -MMD -MP

RM = rm -rf
MKDIR = mkdir -p

# Library Paths
LIBMLX = ../lib/MLX42
MLX_A = $(LIBMLX)/build/libmlx42.a

# Include Directories
HEADERS = -I ../inc -I $(LIBMLX)

# Libraries to Link
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

# Source Directories
MAIN_DIR = src
TUPLE_OPS_DIR = src/tuple_ops
MATRIX_DIR = src/matrix
RAY_SPHERE_DIR = src/ray_sphere

# Source Files
MAIN_FILES = main.c
TUPLE_OPS_FILES = operations.c test_tuple_ops.c test_overall_tuple_ops.c
MATRIX_FILES = matrix.c
RAY_SPHERE_FILES = ray.c test_ray_sphere.c

# Combine Source Files
MAIN = $(addprefix $(MAIN_DIR)/, $(MAIN_FILES))
TUPLE_OPS = $(addprefix $(TUPLE_OPS_DIR)/, $(TUPLE_OPS_FILES))
MATRIX = $(addprefix $(MATRIX_DIR)/, $(MATRIX_FILES))
RAY_SPHERE = $(addprefix $(RAY_SPHERE_DIR)/, $(RAY_SPHERE_FILES))


# All Source Files
SRCS = $(MAIN) $(TUPLE_OPS) $(MATRIX) $(RAY_SPHERE)

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