NAME = gnl.a

CC = cc
CFLAS = -Wall -Werror -Wextra
AR = ar -rcs
RM = rm -f

HEADER = .

SRC = get_next_line.c get_next_line_utils.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re