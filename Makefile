NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf
INC = -I .
CP = cp
SRC = ft_utils_doubly_list.c ft_utils_doubly_list2.c push_swap.c ft_free.c ft_args_validation.c ft_parsing.c \


OBJS = $(SRC:.c=.o)

LIBFT_PATH = libft
LIBFT = ${LIBFT_PATH}/libft.a

all: $(NAME) banner

banner:
	@echo "WIP"

$(NAME): $(OBJS)
	${MAKE} -C ${LIBFT_PATH}
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

.PHONY: all clean fclean re normi banner

clean:
	${MAKE} -C ${LIBFT_PATH} clean
	$(RM) $(OBJS)

fclean: clean
	${MAKE} -C ${LIBFT_PATH} fclean
	$(RM) $(NAME)

re: fclean all

normi:
	@norminette -R CheckForbiddenSourceHeader