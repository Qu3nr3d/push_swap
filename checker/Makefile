CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = checker

SRCS = main.c \
    parse.c \
    lst_functions.c \
    initialize.c \
    checker_utils.c \
    read_stdin.c
	

all: $(NAME) 

$(NAME):
	@$(CC) -g $(CFLAGS) $(SRCS) -o $(NAME)

fclean:
	@rm -f $(NAME)

re: fclean all