BONUS_NAME = philo_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

HEADER = -I .

SRCS = main.c

OBJS = $(SRCS:.c=.o)

all: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS)
	$(CC) $(CFLAGS) $(HEADER) $(OBJS) -o $(BONUS_NAME)

%.o: %.c Makefile
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re