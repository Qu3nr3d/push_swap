CC = gcc

CFLAGS = -Wall -Wextra -Werror -fPIE

NAME = push_swap

BONUS = checker

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

SRCS = lst_functions.c \
	push.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	disorder.c \
	flags.c \
	main.c \
	push_swap_utils_1.c \
	push_swap_utils_2.c \
	push_swap_utils_3.c \
	simple_sort.c \
	medium_sort.c \
	complex_sort.c \
	parse.c \
	print.c \
	metrics.c \
	indexate_utils.c \
	medium_sort_utils.c \
	parse_utils.c \
	read_operations.c

B_SRCS = checker.c

OBJS = $(SRCS:.c=.o)

B_OBJS = $(B_SRCS:.c=.o)

SHARED_FILES = $(filter-out main.o, $(OBJS))

all: $(NAME)

bonus: $(BONUS)

$(BONUS): $(B_OBJS) $(SHARED_FILES) $(LIBFT)
	@$(CC) $(CFLAGS) $(SHARED_FILES) $(B_OBJS) $(LIBFT) -o $(BONUS)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all

%.o: %.c push_swap.h
	@$(CC) -g $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(B_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean