##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	main.c					\
		game_manager.c			\
		duck_movement.c			\
		duck_function.c			\
		compare_vectors.c	    \
		reset_ducks.c		    \
		end_game.c			    \
		score_displayer.c	    \
		display_ducks.c			\
		change_duck_pos.c	    \
		menu_manager.c			\
		button_displayer.c		\
		button_functions.c		\
		check_malloc.c			\
		analyse_event.c

OBJ	=	$(SRC:.c=.o)

FLAGS	=	-lcsfml-graphics -lcsfml-system -L. -lmy -Iinclude

LIBPATH	=	./lib/

NAME	=	my_hunter

all: $(NAME)

$(NAME):
	make -C $(LIBPATH)
	gcc -o $(NAME) $(SRC) $(FLAGS)
	rm -f $(OBJ)

clean:
	make clean -C $(LIBPATH)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBPATH)
	rm -f $(NAME)

re: fclean all
