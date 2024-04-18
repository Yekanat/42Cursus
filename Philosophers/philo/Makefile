NAME = philo

SRCS = \
		philosophers.c \
		check_init.c \
		routine.c

FLAGS = -Wall -Werror -Wextra -g -pthread
CC = gcc $(FLAGS)
RM = rm -f

OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re