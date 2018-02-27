/*
** EPITECH PROJECT, 2018
** display_map.c
** File description:
** Function that displays the two maps
*/

#include "navy.h"

void draw_head(void)
{
	write(1, " |A B C D E F G H\n", 18);
	write(1, "-+---------------\n", 18);
}

void draw_boat(int nb, int j)
{
	if (nb == 0)
		write(1, ".", 1);
	if (nb > 0)
		my_put_nbr(nb);
	if (nb == -1)
		write(1, "x", 1);
	if (nb == -2)
		write(1, "o", 1);
	if (j != 7)
		write(1, " ", 1);
}

void which_positions(int which_map)
{
	if (which_map == 0)
		write(1, "my positions:\n", 14);
	if (which_map == 1)
		write(1, "enemy's positions:\n", 19);
}

void display_map(int positions[8][8], int which_map)
{
	int i = 0;
	int j = 0;
	int number = 49;

	which_positions(which_map);
	draw_head();
	while (i < 8) {
		write(1, &number, 1);
		write(1, "|", 1);
		while (j < 8) {
			draw_boat(positions[i][j], j);
			j = j + 1;
		}
		j = 0;
		i = i + 1;
		number = number + 1;
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}

void can_i_display(int player, int positions[8][8], int enemy[8][8])
{
	if (player == 1) {
		display_map(positions, 0);
		display_map(enemy, 1);
	}
	if (player == 2) {
		display_map(positions, 0);
		display_map(enemy, 1);
	}
}