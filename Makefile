NAME = libftprintf.a

CC = gcc -c

CFLAGS = -Wall -Wextra -Werror

AR = ar r

RM = rm -f
SRC = ft_printf.c\
	  ft_putchar.c\
	  ft_putnbr.c\
	  ft_putstr.c\
	  ft_putnbru.c\
	  ft_puthexa_maj.c\
	  ft_puthexa.c\
	  ft_getadress.c

OBJ = $(subst .c,.o,$(SRC))

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC)
	$(AR) $(NAME) $(OBJ)

clean :
	$(RM) $(OBJ) ${OBJBN}

fclean: clean
	$(RM) $(NAME)

re: fclean all

