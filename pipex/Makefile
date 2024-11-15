NAME = pipex

CC = cc
CFLAGS = 
RM = rm -rf

LIBFT = ./lib/libft

LIBFT_A = $(LIBFT)/libft.a

HEADERS = -I ./inc -I $(LIBFT)

SRCS = src/pipex.c src/utils.c
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = bonus/pipex_bonus.c bonus/utils_bonus.c bonus/process.c bonus/execute.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(LIBFT)/libft.a -o $(NAME)

bonus: $(BONUS_OBJS) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(HEADERS) $(BONUS_OBJS) $(LIBFT)/libft.a -o $(NAME)

$(LIBFT_A):
	@make -C $(LIBFT)

%.o: %.c Makefile
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all bonus clean fclean re