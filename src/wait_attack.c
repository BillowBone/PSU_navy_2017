/*
** EPITECH PROJECT, 2018
** wait_attack.c
** File description:
** Functions that wait for the enemy's signals and tell if it's hitted or not
*/

#include "navy.h"

int wait_attack(void)
{
	communication();
	communication();
	communication();
	return (decrypt_message(0));
}

int hitted_or_not(int letter, int nb, int positions[8][8])
{
	my_putchar(letter + 65);
	my_put_nbr(nb + 1);
	write(1, ": ", 2);
	if (positions[nb][letter] > 0) {
		write(1, "hit\n\n", 5);
		return (1);
	} else {
		write(1, "missed\n\n", 8);
		return (0);
	}
}

void waiting(int positions[8][8], int enemy_pid)
{
	int case1;
	int case2;

	write(1, "waiting for enemy's attack...\n", 30);
	case1 = wait_attack();
	case2 = wait_attack();
	usleep(100000);
	if (hitted_or_not(case1, case2, positions) == 1) {
		kill(enemy_pid, SIGUSR2);
		usleep(10000);
		positions[case2][case1] = -1;
	} else {
		kill(enemy_pid, SIGUSR1);
		usleep(10000);
		if (positions[case2][case1] != -1)
			positions[case2][case1] = -2;
	}
}