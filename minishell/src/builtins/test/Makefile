NAME = test

CC = cc
RM = rm -rf


HEADERS = -I . -I ../../../lib/libft

SRCS = test_pwd.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	@$(CC) $(HEADERS) $(OBJS) libft.a -o $(NAME)

%.o: %.c Makefile
	@$(CC) $(HEADERS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re