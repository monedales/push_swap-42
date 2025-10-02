NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf
INC = -I .
CP = cp

OBJ_DIR = obj

SRC = \
	ft_utils_doubly_list.c ft_utils_doubly_list2.c push_swap.c ft_free.c \
	ft_args_validation.c ft_parsing.c operations-swap.c operations-push.c \
	operations-rotate.c operations-reverse.c ft_sorting.c \

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

LIBFT_PATH = libft
LIBFT = ${LIBFT_PATH}/libft.a

all: $(NAME) banner

banner:
	@echo "WIP"

$(NAME): $(OBJS)
	${MAKE} -C ${LIBFT_PATH}
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

.PHONY: all clean fclean re normi banner

clean:
	${MAKE} -C ${LIBFT_PATH} clean
	$(RM) $(OBJ_DIR)
	$(RM) *.o

fclean: clean
	${MAKE} -C ${LIBFT_PATH} fclean
	$(RM) $(NAME)

re: fclean all

normi:
		norminette -R CheckForbiddenSourceHeader *.c *.h