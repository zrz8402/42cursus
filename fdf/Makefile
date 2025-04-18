NAME  = fdf

CC    = cc
CFLAGS  = -Wall -Wextra -Werror
RM    = rm -rf

LIBMLX  = ./lib/MLX42
LIBFT  = ./lib/libft

HEADERS  = -I . -I $(LIBMLX)/include -I $(LIBFT)

SRCDIR = ./src
SRCS  = main.c map.c utils.c init.c \
		draw.c project.c line.c line_utils.c \
		hooks.c actions.c

OBJS = $(addprefix $(SRCDIR)/, $(SRCS:.c=.o))

MLX_A  = $(LIBMLX)/build/libmlx42.a
LIBFT_A  = $(LIBFT)/libft.a
LIBS	= $(MLX_A) $(LIBFT_A) -ldl -lglfw -pthread -lm 

all: $(NAME)

$(NAME): $(OBJS) $(MLX_A) $(LIBFT_A)
	@echo "Linking object files to create executable: $(NAME)"
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "Executable created: $(NAME)"

%.o: %.c Makefile fdf.h
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "Compile complete."

$(MLX_A):
	@echo "Building MLX library..."
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	@echo "MLX library built successfully."

$(LIBFT_A):
	@echo "Building libft library..."
	@make -C $(LIBFT)
	@echo "libft library built successfully."

clean:
	@echo "Cleaning up object files..."
	@$(RM) $(OBJS)
	@echo "Cleaning up libft directory..."
	@make clean -C $(LIBFT)

fclean: clean
	@echo "Removing executable: $(NAME)"
	@$(RM) $(NAME)
	@echo "Cleaning up MLX build directory..."
	$(RM) $(LIBMLX)/build
	@echo "Cleaning up libft directory..."
	@make fclean -C $(LIBFT)
	@echo "Clean complete."

re: fclean all

.PHONY: all clean fclean re