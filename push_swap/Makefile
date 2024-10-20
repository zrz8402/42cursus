NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC_PATH = ./src/
INCLUDE_PATH = ./inc/
LIBFT_PATH = ./lib/libft/

HEADERS = -I $(INCLUDE_PATH) -I $(LIBFT_PATH)

CFILES = main.c parse.c
SRCS = $(addprefix $(SRC_PATH), $(CFILES))

OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFT_PATH)libft.a

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(LIBFT) -o $(NAME)

%.o : $(SRC_PATH)%.c Makefile $(INCLUDE_PATH)push_swap.h
	@echo "Compiling $< with headers: $(HEADERS)"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re