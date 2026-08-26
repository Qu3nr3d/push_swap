CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = checker

SRCS = main.c \
    parse.c \
    lst_functions.c \
    initialize.c \
    checker_utils_1.c \
    read_stdin.c \
    checker_utils_2.c \
    swap.c \
    push.c \
    rotate.c \
    reverse_rotate.c
	

all: $(NAME) 

$(NAME):
	@$(CC) -g $(CFLAGS) $(SRCS) -o $(NAME)

fclean:
	@rm -f $(NAME)

re: fclean all