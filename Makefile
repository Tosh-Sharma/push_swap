NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_SRC_FILES = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_cpyarray.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_superatoi.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putunbr_fd.c \
		ft_putnbr_16.c \
		ft_putnbr_16_caps.c \
		ft_revstr.c \
		ft_straddchar.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

LIB_SRC = $(addprefix libft/, $(LIBFT_SRC_FILES))
SRCS = 	push_swap.c \
		core/lngst_sbsqnc.c \
		core/super_lis.c \
		core/push_items_in_b.c \
		core/merge_stacks.c \
		core/calculate_m.c \
		core/merge_sort.c \
		core/copy_and_sort.c \
		core/sorting_in_b.c \
		core/moves_to_make.c \
		core/sort_three_numbers.c \
		core/sort_five_numbers.c \
		stack_moves/swap.c \
		stack_moves/push.c \
		stack_moves/rotate.c \
		stack_moves/rev_rotate.c \
		helpers/utils.c \
		helpers/utils_2.c \
		helpers/init_array.c \
		helpers/print_array.c \
		helpers/rev_array.c \
		helpers/special_moves_a.c \
		helpers/special_moves_b.c \
		$(LIB_SRC)

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	make -C ./libft
	${CC} ${CFLAGS} -o ${@} ${^} libft/libft.a

%.o: %.c
	${CC} ${CFLAGS} -o ${@} -c ${@:.o=.c}

re: fclean all

fclean: clean
	rm -f ${NAME}

clean:
	rm -f ${OBJS} ${BONUS_OBJS}

.PHONY: clean fclean re all
