CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME_BONUS = checker_bonus

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

all: $(NAME_BONUS) 

$(NAME_BONUS):
	@$(CC) -g $(CFLAGS) $(SRCS_BONUS) -o $(NAME_BONUS)

fclean:
	@rm -f $(NAME)

re: fclean all