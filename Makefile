# Program name
NAME = push_swap
BONUS_NAME = checker

# Directories
SRC_DIR = src
SRC_BONUS_DIR = src_bonus
INCLUDE_DIR = includes
LIBFT_DIR = libft
OBJ_DIR = obj
OBJ_BONUS_DIR = obj_bonus
# DEBUG_DIR = debug

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR)
AR = ar rcs
RM = rm -rf

# Source files
SRC = \
	ft_utils_doubly_list.c ft_utils_doubly_list2.c ft_sorting.c \
	push_swap.c ft_free.c ft_rotation_helpers.c ft_algorithm.c \
	ft_args_validation.c ft_parsing.c operations-swap.c operations-push.c \
	operations-rotate.c operations-reverse.c ft_costs.c ft_costs2.c \
	ft_costs_b_to_a.c ft_movements.c ft_chunks.c \

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Bonus source files - only checker-specific files
SRC_BONUS = \
	checker.c read_operations.c operations_checker.c \
	operations_checker2.c operations_checker3.c \

# Shared files needed for checker (reuse from src/)
SRC_SHARED = \
	ft_utils_doubly_list.c ft_utils_doubly_list2.c ft_free.c \
	ft_args_validation.c ft_parsing.c operations-swap.c operations-push.c \
	operations-rotate.c operations-reverse.c \

OBJS_BONUS = $(addprefix $(OBJ_BONUS_DIR)/, $(SRC_BONUS:.c=.o))
OBJS_SHARED = $(addprefix $(OBJ_BONUS_DIR)/, $(SRC_SHARED:.c=.o))

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@$(MAKE) banner

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

# Bonus target
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS) $(OBJS_SHARED) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(OBJS_SHARED) $(LIBFT) -o $(BONUS_NAME)
	@$(MAKE) bonus-banner

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@mkdir -p $(OBJ_BONUS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_BONUS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@


# Banner rules
banner:
	@echo ""
	@echo "██████╗ ██╗   ██╗███████╗██╗  ██╗    ███████╗██╗    ██╗ █████╗ ██████╗ "
	@echo "██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔════╝██║    ██║██╔══██╗██╔══██╗"
	@echo "██████╔╝██║   ██║███████╗███████║    ███████╗██║ █╗ ██║███████║██████╔╝"
	@echo "██╔═══╝ ██║   ██║╚════██║██╔══██║    ╚════██║██║███╗██║██╔══██║██╔═══╝ "
	@echo "██║     ╚██████╔╝███████║██║  ██║    ███████║╚███╔███╔╝██║  ██║██║     "
	@echo "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     "
	@echo ""
	@echo "           🐱 Louis    vs    Ozzy 🐱"
	@echo "            /\\_/\\  ← → ← →  /\\_/\\" 
	@echo "           ( o.o )  PUSH   ( -.- )"
	@echo "            > ^ <   SWAP    > ^ <"
	@echo "         Stack A           Stack B"
	@echo ""
	@echo "Compiled successfully! Ready to sort some stacks!"
	@echo ""

bonus-banner:
	@echo ""
	@echo " ██████╗██╗  ██╗███████╗ ██████╗██╗  ██╗███████╗██████╗ "
	@echo "██╔════╝██║  ██║██╔════╝██╔════╝██║ ██╔╝██╔════╝██╔══██╗"
	@echo "██║     ███████║█████╗  ██║     █████╔╝ █████╗  ██████╔╝"
	@echo "██║     ██╔══██║██╔══╝  ██║     ██╔═██╗ ██╔══╝  ██╔══██╗"
	@echo "╚██████╗██║  ██║███████╗╚██████╗██║  ██╗███████╗██║  ██║"
	@echo " ╚═════╝╚═╝  ╚═╝╚══════╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝"
	@echo ""
	@echo "    🕵️ Louis is watching... 👀     Ozzy is judging... 😾"
	@echo "     /\\_/\\    'Did you         /\\_/\\    'That looks"
	@echo "    ( ಠ.ಠ)     sort it?'       ( ͡° ͜ʖ ͡°)   suspicious...'"
	@echo "     > ^ <                      > ^ <"
	@echo ""
	@echo "Checker ready! Time to validate those operations!"
	@echo ""

.PHONY: all clean fclean re normi banner bonus-banner bonus

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ_DIR) $(OBJ_BONUS_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

normi:
	@norminette -R CheckForbiddenSourceHeader $(addprefix $(SRC_DIR)/, $(SRC)) $(INCLUDE_DIR)/*.h