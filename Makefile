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

TESTS_SRC	=	./src/communication.c	\
			./src/decrypt_message.c	\
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
			./tests/test.c	\
			./tests/test2.c	\
			./tests/test3.c	\
			./tests/test4.c	\
			./tests/test5.c	\

OBJ	=	$(SRC:.c=.o)

TESTS_OBJ	=	$(TESTS_SRC:.c=.o)

NAME	=	navy

TESTS_NAME	=	test

CFLAGS	=	-I./include

TFLAGS	=	-I./include -lcriterion

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc $(OBJ) $(CFLAGS) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

$(TESTS_NAME):	$(TESTS_OBJ)
		gcc $(TESTS_OBJ) $(TFLAGS) -o $(TESTS_NAME) --coverage

tests_run:	$(TESTS_NAME)
		./test

tests_clean:
		rm -f $(TESTS_OBJ)
		rm -f *.gc*
		rm -f $(TESTS_NAME)
		rm -f *.o