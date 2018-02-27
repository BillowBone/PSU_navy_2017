/*
** EPITECH PROJECT, 2018
** game_loop.c
** File description:
** This is my game_loop for the navy
*/

#include "navy.h"

int game_loop(int player, int enemy_pid, int who_play, int positions[8][8])
{
	int enemy[8][8];

	initialize(enemy);
	while (count_hits(positions) != 14 && count_hits(enemy) != 14) {
		if (who_play == 0) {
			can_i_display(player, positions, enemy);
			waiting(positions, enemy_pid);
			write(1, "\n", 1);
			who_play = 1;
		} else {
			can_i_display(player, positions, enemy);
			attack(enemy, enemy_pid);
			who_play = 0;
		}
	}
	return (end_message(positions, enemy));
}