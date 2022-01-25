NAME = push_swap
CC = gcc
LIBFT_PATH=libft_expanded/
LIBFT_NAME=libft.a
LIBFT  = $(addprefix $(LIBFT_PATH), $(LIBFT_NAME))
CFLAGS = -Wall -Werror -Wextra
SRCS = push_swap.c stack.c ft_atoi_pushswap.c \
		operations.c sort/sort.c sort/scroll.c sort/insert_sort_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): git_submodule lib $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT)

git_submodule:
	@git submodule init
	@git submodule update

lib:
	$(MAKE) -C $(LIBFT_PATH)

clean:
	@rm -f $(OBJS)
	@rm -f .*.swp
	@rm -f */.*.swp
	@rm -f a.out
	$(MAKE) clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
