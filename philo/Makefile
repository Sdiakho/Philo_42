CC		= cc
CFLAGS	= -Wall -Wextra -Werror -fsanitize=thread
SRCS	= clean.c \
		display.c \
		error.c \
		ft_ato.c \
		init.c \
		monitor.c \
		parser.c \
		philo.c \
		routine.c \
		thread.c \
		time.c \
		utils.c

OBJS	= $(SRCS:%.c=%.o)
NAME	= philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(DIR)/%.o: $(DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re