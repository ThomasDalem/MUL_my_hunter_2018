##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	my_putchar.c	\
		my_putstr.c		\
		my_revstr.c		\
		my_strcat.c		\
		my_strlen.c		\
		my_strcpy.c		\
		my_put_nbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	gcc -c $(SRC)
	ar rc ../$(NAME) $(OBJ)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

re: fclean all
