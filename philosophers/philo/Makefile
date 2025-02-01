NAME = philo
BONUS_NAME = philo_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread
RM = rm -f

HEADER = -I .

SRCS = main.c init.c stimulation.c monitor.c routines.c utils.c

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