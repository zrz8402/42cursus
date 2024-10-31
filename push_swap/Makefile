NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = 
RM = rm -rf

SRC_PATH = ./src
INCLUDE_PATH = ./inc
LIBFT_PATH = ./lib/libft

HEADERS = -I $(INCLUDE_PATH) -I $(LIBFT_PATH)

CFILES = parse.c stack.c utils.c sort.c \
		sortn.c lis.c sortn_utils.c move.c\
		op_swap.c op_rotate.c op_rrotate.c op_push.c

MAIN_SRC = src/push_swap.c
BONUS_SRC = src/checker.c

OTHER_SRCS = $(addprefix $(SRC_PATH)/, $(CFILES))


OTHER_OBJS = $(OTHER_SRCS:.c=.o)
MAIN_OBJ = $(MAIN_SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME) $(BONUS)

bonus: $(BONUS)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(MAIN_OBJ) $(OTHER_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(HEADERS) $(MAIN_OBJ) $(OTHER_OBJS) $(LIBFT) -o $(NAME)

$(BONUS): $(BONUS_OBJS) $(OTHER_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(HEADERS) $(BONUS_OBJS) $(OTHER_OBJS) $(LIBFT) -o $(BONUS)

%.o : %.c Makefile $(INCLUDE_PATH)/push_swap.h
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	@$(RM) $(MAIN_OBJ) $(OTHER_OBJS) $(BONUS_OBJS)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@$(RM) $(NAME) $(BONUS)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all bonus clean fclean re