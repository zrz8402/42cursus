NAME = test

CC = cc
RM = rm -rf


HEADERS = -I . -I ../lib/libft
LIBS = -lreadline libft.a

SRCS = main.c env.c env_utils.c unset.c \
		cd.c  echo.c  exit.c  export.c pwd.c \
		builtin.c process.c  redir.c  execute.c  
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	@$(CC) $(HEADERS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c Makefile
	@$(CC) $(HEADERS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
