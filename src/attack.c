/*
** EPITECH PROJECT, 2018
** attack.c
** File description:
** Funtion that makes the player attacks
*/

#include "navy.h"

void attack(int enemy[8][8], int enemy_pid)
{
	int *coord;

	coord = take_input();
	send_it(coord[0], coord[1], enemy_pid);
	my_putchar(coord[0] + 65);
	my_put_nbr(coord[1] + 1);
	write(1, ": ", 2);
	wait_response();
	analyse_response(coord, enemy);
	free(coord);
}
