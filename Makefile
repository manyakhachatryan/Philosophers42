NAME		= philo
SRCS		= $(wildcard src/*/*.c)
SRCS		+= $(wildcard src/*.c)
OBJS		= $(SRCS:.c=.o)
INCLUDES	= ./includes
CFLAGS		= -Wall -Wextra -Werror 
RM			= rm -f
CC			= cc


%.o:%.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) -o $(NAME)

clean	:
		$(RM) $(OBJS)

fclean	: 	clean
			$(RM) $(NAME)  
			rm -rf ~/LIbrary/Caches

re		:fclean all
.PHONY: all clean fclean re