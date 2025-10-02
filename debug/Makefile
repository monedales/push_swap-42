# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mona <mona@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/02 20:30:00 by mona              #+#    #+#              #
#    Updated: 2025/10/02 18:58:22 by mona             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Debug program name
NAME		= push_swap_debug

# Directories
SRC_DIR		= ../src
INCLUDE_DIR	= ../includes
LIBFT_DIR	= ../libft
OBJ_DIR		= obj

# Source files
DEBUG_SRCS	= push_swap_debug.c
SRC_SRCS	= ft_utils_doubly_list.c ft_utils_doubly_list2.c ft_free.c \
			  ft_args_validation.c ft_parsing.c operations-swap.c \
			  operations-push.c operations-rotate.c operations-reverse.c \
			  ft_sorting.c

# Object files
DEBUG_OBJS	= $(DEBUG_SRCS:%.c=$(OBJ_DIR)/%.o)
SRC_OBJS	= $(SRC_SRCS:%.c=$(OBJ_DIR)/%.o)
ALL_OBJS	= $(DEBUG_OBJS) $(SRC_OBJS)

# Libraries
LIBFT		= $(LIBFT_DIR)/libft.a

# Compiler and flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I $(INCLUDE_DIR) -I $(SRC_DIR)

# Colors for output
RESET		= \033[0m
BOLD		= \033[1m
RED			= \033[91m
GREEN		= \033[92m
YELLOW		= \033[93m
BLUE		= \033[94m
MAGENTA		= \033[95m
CYAN		= \033[96m

# Rules
all: $(NAME)

$(NAME): $(OBJ_DIR) $(ALL_OBJS) $(LIBFT)
	@echo "$(CYAN)$(BOLD)Linking debug executable...$(RESET)"
	@$(CC) $(CFLAGS) $(ALL_OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(BOLD)🔍 Debug version ready! Use: ./$(NAME) <numbers>$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@echo "$(YELLOW)Compiling debug: $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(YELLOW)Compiling source: $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "$(BLUE)$(BOLD)Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@echo "$(RED)Cleaning debug objects...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)Removing debug executable...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

# Test targets
test-simple:
	@echo "$(MAGENTA)$(BOLD)Testing 3-element sort:$(RESET)"
	@./$(NAME) 3 2 1
	@echo "\n$(MAGENTA)$(BOLD)Testing 5-element sort:$(RESET)"
	@./$(NAME) 5 4 3 2 1

test-sorted:
	@echo "$(MAGENTA)$(BOLD)Testing already sorted:$(RESET)"
	@./$(NAME) 1 2 3 4 5

test-all: test-simple test-sorted

normi:
	@if command -v norminette >/dev/null 2>&1; then \
		norminette -R CheckForbiddenSourceHeader *.c $(SRC_DIR)/*.c $(INCLUDE_DIR)/*.h; \
	elif [ -f ~/Library/Python/3.9/bin/norminette ]; then \
		~/Library/Python/3.9/bin/norminette -R CheckForbiddenSourceHeader *.c $(SRC_DIR)/*.c $(INCLUDE_DIR)/*.h; \
	elif [ -f ~/.local/bin/norminette ]; then \
		~/.local/bin/norminette -R CheckForbiddenSourceHeader *.c $(SRC_DIR)/*.c $(INCLUDE_DIR)/*.h; \
	else \
		echo "❌ Norminette not found!"; \
		echo "📝 To install norminette, run:"; \
		echo "   pip3 install --user norminette"; \
		exit 1; \
	fi

.PHONY: all clean fclean re test-simple test-sorted test-all normi