NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

HEADER = -I ./inc

SRC_DIR = ./src
SRC = 

OBJS = $(addprefix $(SRC)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(HEADER) $(OBJS) -o $(NAME)

%.o : %.c Makefile ./inc/push_swap.h
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:
	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re