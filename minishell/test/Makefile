NAME = test

CC = cc
RM = rm -rf


HEADERS = -I . -I ../lib/libft
LIBS = -lreadline libft.a

MAIN = main.c init.c utils.c
SIG = signal.c
PARSE = 
EXEC = process.c redir.c execute.c builtin.c cleanup.c
BUILTIN = env.c unset.c cd.c echo.c exit.c export.c pwd.c

SRCS = main.c init.c utils.c \
		signal.c \
		process.c redir.c execute.c builtin.c cleanup.c \
		env.c unset.c cd.c echo.c exit.c export.c pwd.c \

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
