CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = $(shell find ! -name "rotate.c" ! -name "swap.c" ! -name "push.c" -name "*.c" -name "push_swap.h")

all: 
	$(CC) -g $(CFLAGS) lst_functions.c push_swap.h operations_checker.c push.c