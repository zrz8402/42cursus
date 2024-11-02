NAME = pipex

CC = cc
CFLAGS =
RM = rm -rf

LIBFT = ./lib/libft

LIBFT_A = $(LIBFT)/libft.a

HEADERS = -I . -I $(LIBFT)

SRCS = pipex.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(LIBFT)/libft.a -o $(NAME)

$(LIBFT_A):
	@make -C $(LIBFT)

%.o: %.c Makefile pipex.h
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re