NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

HEADER = -I .

SRCS = main.c init.c simulation.c monitor.c routine.c utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(HEADER) $(OBJS) -o $(NAME)

%.o: %.c Makefile
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re