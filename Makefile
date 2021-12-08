NAME = push_swap

CC = clang

FLAGS    = -Wall -Wextra -Werror -g

DEL = /bin/rm -f

SRCS =     srcs/check_arg.c \
        srcs/exec_cmd.c \
        srcs/free.c \
        srcs/main.c \
        srcs/move_utils.c \
        srcs/move.c \
        srcs/operations.c \
        srcs/parsing.c \
        srcs/sort_utils.c \
        srcs/sort_utils_2.c \
        srcs/sort.c \
        srcs/stack.c \
				# srcs/sorted_check.c \

SRCS_O    = ${SRCS:.c=.o}
all: $(NAME)

LIBC    = ar -rcs

%.o: %.c
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${SRCS_O}
			make bonus -C ./libft/
		 $(CC) $(FLAGS) $(SRCS_O) -o $(NAME) -L ./libft/ -lft

fclean: clean
		$(DEL) $(NAME)
		make fclean -C ./libft/

clean:
		$(DEL) $(SRCS_O)
		make clean -C ./libft/

re: fclean all
