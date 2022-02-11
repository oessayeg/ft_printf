NAME = libftprintf.a

SRCS = ft_printf.c ft_putfunctions.c ft_putfunctions2.c

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRCS:.c=.o)
	ar -rc $(NAME) $^

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean :
	rm -f $(SRCS:.c=.o)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
