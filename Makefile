# Program name
NAME = push_swap

# Directories
SRC_DIR = src
INCLUDE_DIR = includes
LIBFT_DIR = libft
OBJ_DIR = obj
# DEBUG_DIR = debug

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR)
AR = ar rcs
RM = rm -rf

# Source files
SRC = \
	ft_utils_doubly_list.c ft_utils_doubly_list2.c ft_utils_position.c \
	ft_utils_stack_search.c push_swap.c ft_free.c \
	ft_args_validation.c ft_parsing.c operations-swap.c operations-push.c \
	operations-rotate.c operations-reverse.c ft_sorting.c ft_costs.c ft_costs2.c \
	ft_costs_b_to_a.c ft_movements.c ft_chunks.c ft_algorithm.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Debug target
# debug:
# 	@$(MAKE) -C $(DEBUG_DIR)

.PHONY: all clean fclean re normi banner debug

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
# 	@$(MAKE) -C $(DEBUG_DIR) clean
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
# 	@$(MAKE) -C $(DEBUG_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

normi:
	norminette -R CheckForbiddenSourceHeader $(SRC_DIR)/*.c $(INCLUDE_DIR)/*.h