NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf
INC = -I .
SRC = \
	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_split.c \
	ft_strlcpy.c ft_strlcat.c ft_strlen.c ft_strncmp.c \
	ft_strnstr.c ft_strchr.c ft_strdup.c ft_strrchr.c \
	ft_strmapi.c ft_strtrim.c ft_striteri.c ft_strjoin.c \
	ft_substr.c ft_tolower.c ft_toupper.c \
	ft_printf.c ft_print_chars.c ft_print_hexptr.c ft_print_numbers.c \
	get_next_line.c ft_memdel.c \

SRC_BONUS =	\
	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c	\

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME) banner

banner:
	@echo ""
	@echo "                               ,----."
	@echo "                              ( WOW! )                         .-."
	@echo "                               \`----' _                         \ \ "
	@echo "                                     (_)                         \ \ "
	@echo "                                         O                       | |"
	@echo "                    |\\ /\\                  o                     | |"
	@echo "    __              |,\\(_\\_                  . /\\---/\\   _,---._ | |"
	@echo "   ( (              |,\\\`   \`-^.               /^   ^  \\,\'       \`. ;"
	@echo "    \\ \\             :    \`-'   )             ( O   O   )           ;"
	@echo "     \\ \\             \\        ;               \`.=o=__,'            \\"
	@echo "      \\ \\             \`-.   ,'                  /         _,--.__   \\"
	@echo "       \\ \\ ____________,'  (                   /  _ )   ,'   \`-. \`-. \\"
	@echo "        ; '                ;                  / ,' /  ,'        \\ \\ \\ \\"
	@echo "        \\                 /___,-.            / /  / ,'          (,_)(,_)"
	@echo "         \`,    ,_____|  ;'_____,'           (,;  (,,)      oZZy"
	@echo "       ,-\" \\  :      | :"
	@echo "      ( .-\" \\ \`.__   | |"
	@echo "       \\__)  \`.__,'  |__)  louiS"

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)



bonus: $(OBJS) $(OBJS_BONUS)
	@$(MAKE) OBJS="$(OBJS) $(OBJS_BONUS)"

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

normi:
	@norminette -R CheckForbiddenSourceHeader

.PHONY: all clean fclean re normi banner