SRC = main.c error_checker.c error_checker_utilities.c \
	  algorithms/simple_algo.c operations/push.c \
	  operations/rotate.c operations/reverse_rotate.c \
	  options_selector.c 

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

DEP = $(OBJ:.o=.d)

NAME = push_swap

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re bonus make_lib

all: make_lib $(NAME)

make_lib:
	(cd libft && make bonus)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L./libft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJ) $(DEP) ; (cd libft && make clean)

fclean: clean
	rm -rf $(NAME) ; (cd libft && make fclean)

re: fclean all

-include $(DEP)