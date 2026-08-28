CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

NAME_BONUS = checker_bonus

SRCS = lst_functions.c \
	push.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	disorder.c \
	flags.c \
	main.c \
	initialize.c \git 
	push_swap_utils_1.c \
	push_swap_utils_2.c \
	complex_sort.c \
	parse.c \
	print.c \
	simple_sort.c \
	metrics.c \
	indexate_utils.c \
	medium_sort_utils.c \
	medium_sort.c \
	functions_for_ARG.c \
	ft_split.c

SRCS_BONUS = bonus_checker_bonus.c \
    bonus_parse.c \
    bonus_lst_functions.c \
    bonus_initialize.c \
    bonus_checker_utils_1.c \
    bonus_read_operations.c \
    bonus_checker_utils_2.c \
    bonus_swap.c \
    bonus_push.c \
    bonus_rotate.c \
    bonus_reverse_rotate.c \
    bonus_read_operations_utils_1.c \
    bonus_read_operations_utils_2.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(SRCS) push_swap.h
	@$(CC) -g $(CFLAGS) -c $(SRCS) -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_BONUS): $(SRCS_BONUS) bonus_checker.h
	@$(CC) -g $(CFLAGS) -c $(SRCS_BONUS) -o $@

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re: clean all