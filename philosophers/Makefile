NAME = philo
BONUS_NAME = philo_bonus

CC = cc
CFLAGS =
RM = rm -f

HEADER = -I .

SRCS =

OBJS = $(SRCS: .c=.o)

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