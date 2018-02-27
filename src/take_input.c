/*
** EPITECH PROJECT, 2018
** take_input.c
** File description:
** Function that takes the input from user
*/

#include "navy.h"

int is_it_valid(char *input)
{
	if (input == NULL)
		return (0);
	if (my_strlen(input) != 2)
		return (0);
	if (input[0] < 65 || input[0] > 72)
		return (0);
	if (input[1] < 49 || input[1] > 56)
		return (0);
	return (1);
}

int *take_input(void)
{
	int *coord = malloc(sizeof(int) * 3);
	char *input;

	write(1, "attack: ", 8);
	input = get_next_line(0);
	while (is_it_valid(input) == 0) {
		if (is_it_valid(input) == 0)
			write(1, "wrong position\n", 15);
		write(1, "attack: ", 8);
		input = get_next_line(0);
		if (my_strlen(input) == 0)
			get_next_line(-1);
	}
	coord[0] = input[0] - 65;
	coord[1] = input[1] - 49;
	coord[2] = -1;
	free(input);
	return (coord);
}