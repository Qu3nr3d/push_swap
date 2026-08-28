CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = checker

SRCS = main.c \
    parse.c \
    lst_functions.c \
    initialize.c \
    checker_utils_1.c \
    read_operations.c \
    checker_utils_2.c \
    swap.c \
    push.c \
    rotate.c \
    reverse_rotate.c \
    read_operations_utils_1.c \
    read_operations_utils_2.c
	

all: $(NAME) 

$(NAME):
	@$(CC) -g $(CFLAGS) $(SRCS) -o $(NAME)

fclean:
	@rm -f $(NAME)

re: fclean all