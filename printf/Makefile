SRCS = ft_printstr.c ft_putchar.c ft_puthexalow.c ft_uns_int.c ft_printf.c ft_put_adress.c ft_puthexa.c ft_putnbr.c ft_strlcpy.c ft_strlen.c
CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME) : $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
	ar rcs $(NAME) $@
clean :
	rm -f $(OBJS) 

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re