NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
		parse.c \
		bench.c \
		bench_counts.c \
		strategy.c \
		valid.c \
		utils.c \
		free.c \
		wrapper.c \
		operation0.c \
		operation1.c \
		operations2.c \
		operations3.c \
		simple.c \
		medium.c \
		medium_utils.c \
		complex.c \
		split_utils.c \
		libft.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c pushswap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
