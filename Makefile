NAME=libftprintf.a
CFLAGS= -Wall -Wextra -Werror
SRC=ft_printf.c\
	ft_putchar.c\
	ft_putstr.c\
	ft_putnbr.c\
	ft_puthex.c\
	ft_putnbr_unsigned.c\
	ft_putaddr.c\
	ft_strlcpy.c

OBJ=$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^

$(OBJ): $(SRC)
	cc -c $^

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all