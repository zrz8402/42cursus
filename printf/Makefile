NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

HEADER = .
SRC = ft_printf.c printf_utils.c print_char.c print_str.c \
		print_ptr.c print_int.c print_hex.c print_unsigned.c

OBJECT = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT)
		$(AR) $(NAME) $(OBJECT)

%.o:%.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

clean:
	$(RM) $(OBJECT)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re