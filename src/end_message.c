/*
** EPITECH PROJECT, 2018
** end_message.c
** File description:
** Function that displays the right message at the end of the game
*/

#include "navy.h"

int end_message(int positions[8][8], int enemy[8][8])
{
	if (count_hits(positions) == 14) {
		write(1, "Enemy won\n", 10);
		return (1);
	}
	if (count_hits(enemy) == 14) {
		write(1, "I won\n", 6);
		return (0);
	}
	return (0);
}