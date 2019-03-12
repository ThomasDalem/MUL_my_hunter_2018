##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c			\
		src/game_manager.c		\
		src/duck_movement.c		\
		src/duck_function.c		\
		src/compare_vectors.c		\
		src/reset_ducks.c		\
		src/end_level.c			\
		src/score_displayer.c		\
		src/display_ducks.c		\
		src/change_duck_pos.c		\
		src/menu_manager.c		\
		src/button_displayer.c		\
		src/button_functions.c		\
		src/check_malloc.c		\
		src/display_cursor.c		\
		src/game_functions.c		\
		src/end_manager.c		\
		src/health_displayer.c		\
		src/my_int_to_str.c		\
		src/analyse_event.c

FLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -L./src/lib -lmy -Iinclude -g3

LIBPATH	=	./src/lib/

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
