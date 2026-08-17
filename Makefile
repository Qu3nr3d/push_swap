CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = $(shell find ! -name "rotate.c" ! -name "swap.c" ! -name "push.c" -name "*.c" -name "push_swap.h")

all: 
	$(CC) -g $(CFLAGS) lst_functions.c \
	push.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	disorder.c \
	flags.c \
	main.c \
	push_swap.h \
	push_swap_utils.c \
	initialize.c \
	complex_sort.c \
	parse.c
