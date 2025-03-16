# By: kmartin < kmartin@student.42bangkok.com 
# Compile libft library of C functions

# Library
NAME=libft.a

# Header file
HEAD=libft.h
## Note that submodule headers are referenced in
##  the submodule .c files (e.g. ft_printf)

# Compiler and flags
CC=cc
CFLAGS=-Wall -Wextra -Werror -I.
## -I flags indicate locations of headers
## (Submodule functions can reference their own .h)

# Source files to be included in the library
SRCS=ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c \

# Bonus source files (don't include in standard make)
B_SRCS=ft_lstadd_back_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstclear_bonus.c \
ft_lstdelone_bonus.c \
ft_lstiter_bonus.c \
ft_lstlast_bonus.c \
ft_lstmap_bonus.c \
ft_lstnew_bonus.c \
ft_lstsize_bonus.c

# Source files for ft_printf submodule (include with 'full' make)
P_SRCS = ft_printf/arg_to_str.c \
ft_printf/arg_to_str_utils.c \
ft_printf/format_strings.c \
ft_printf/ft_printf.c \
ft_printf/get_arg_info.c \
ft_printf/handle_arg_types.c \
ft_printf/parse_specifiers.c \

# Source files for get_next_line submodule (include with 'full' make)
G_SRCS = get_next_line/get_next_line.c 

# Object files 
OBJS=$(SRCS:%.c=%.o)

# Bonus Object files
B_OBJS=$(B_SRCS:%.c=%.o)

# ft_printf Object files (submodule in named subdirectory)
P_OBJS=$(P_SRCS:ft_printf/%.c=ft_printf/%.o)

# get_next_line Object files (submodule in named subdirectory)
G_OBJS=$(G_SRCS:get_next_line/%.c=get_next_line/%.o)

# Prevent confusion with files named like rules
.PHONY: all bonus full clean fclean re

# Default target checks library and dependencies
all: $(NAME)

# Create the library if missing or objects changed
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compile bonus code
bonus: $(NAME)-bonus

# Intermediary target for library including bonus code
# The use of 'touch' ensures that the 'bonus' rule only executes
#   the instructions below when dependencies have changed
$(NAME)-bonus: $(OBJS) $(B_OBJS)
	ar rcs $(NAME) $(OBJS) $(B_OBJS)
	touch $(NAME)-bonus 

# Compile full library (bonus code and all submodules) 
full: $(NAME)-full
 
# Intermediary target for full library
# The use of 'touch' ensures that the 'full' rule only executes
#   the instructions below when dependencies have changed
$(NAME)-full: $(OBJS) $(B_OBJS) $(P_OBJS) $(G_OBJS)
	ar rcs $(NAME) $(OBJS) $(B_OBJS) $(P_OBJS) $(G_OBJS)
	touch $(NAME)-full

# Compile source files if .c changed
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and intermediary files
clean:
	rm -f $(OBJS) $(B_OBJS) $(P_OBJS) $(G_OBJS)
	rm -f $(NAME)-bonus $(NAME)-full

# Clean up all files
fclean: clean
	rm -f $(NAME)

# Rebuild library from scratch (excluding bonus and submodules)
re: fclean all
