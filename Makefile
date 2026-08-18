CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

OBJS = $(SRC:.c=.o)

SRCS = lst_functions.c \
	push.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	disorder.c \
	flags.c \
	main.c \
	push_swap.h \
	initialize.c \
	push_swap_utils_1.c \
	push_swap_utils_2.c \
	complex_sort.c \
	parse.c \
	print.c \
	simple_sort.c \
	medium_sort.c \
	metrics.c

all: $(NAME) 

$(NAME):
	@$(CC) -g $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -f $(NAME)

re: clean all