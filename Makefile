##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## This is my Makefile for the navy project
##

SRC	=	./src/communication.c	\
		./src/decrypt_message.c	\
		./src/main.c	\
		./src/encrypt_message.c	\
		./src/manage_args.c	\
		./src/my_strcmp.c	\
		./src/my_str_isnum.c	\
		./src/my_getnbr.c	\
		./src/my_put_nbr.c	\
		./src/get_next_line.c	\
		./src/get_next_line2.c	\
		./src/errors.c	\
		./src/my_strlen.c	\
		./src/game_loop.c	\
		./src/first_contact.c	\
		./src/get_positions.c	\
		./src/display_map.c	\
		./src/my_putchar.c	\
		./src/count_hits.c	\
		./src/wait_attack.c	\
		./src/take_input.c	\
		./src/wait_response.c	\
		./src/end_message.c	\
		./src/attack.c	\
		./src/my_pid.c	\
		./src/my_strcpy_k.c	\
		./src/count_boats.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

CFLAGS	=	-I./include

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc $(OBJ) $(CFLAGS) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
