NAME  = fdf

CC    = cc
CFLAGS  = -Wall -Werror -Wextra -Wunreachable-code -Ofast
RM    = rm -rf

LIBMLX  = ./lib/MLX42
LIBFT  = ./lib/libft

HEADERS  = -I ./include -I $(LIBMLX)/include -I $(LIBFT)

MLX_A  = $(LIBMLX)/build/libmlx42.a
LIBFT_A  = $(LIBFT)/libft.a

LIBS	= $(MLX_A) $(LIBFT_A) -ldl -lglfw -pthread -lm 

SRCS  = src/main.c src/read_map.c src/error.c

OBJS  = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(MLX_A) $(LIBFT_A) $(OBJS)
	@echo "Linking object files to create executable: $(NAME)"
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "Executable created: $(NAME)"

$(MLX_A):
	@echo "Building MLX library..."
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	@echo "MLX library built successfully."

$(LIBFT_A):
	@echo "Building libft library..."
	@make -C $(LIBFT)
	@echo "libft library built successfully."

%.o: %.c
	@echo "Compiling: $(notdir $<)"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "Compiled: $(notdir $<) to $@"

clean:
	@echo "Cleaning up object files..."
	$(RM) $(OBJS)
	@echo "Cleaning up MLX build directory..."
	$(RM) $(LIBMLX)/build
	@echo "Cleaning up libft build directory..."
	make fclean -C $(LIBFT)

fclean: clean
	@echo "Removing executable: $(NAME)"
	$(RM) $(NAME)
	@echo "Clean complete."

re: fclean all

.PHONY: all clean fclean re