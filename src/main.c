/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** This is my main function for the navy project
*/

#include "navy.h"

int main(int argc, char *argv[])
{
	int p2pid = 0;
	int positions[8][8];

	if (manage_args(argc, argv) != 0)
		return (84);
	my_pid();
	if (argc == 2) {
		write(1, "waiting for enemy connection...\n\n", 33);
		p2pid = first_received();
		write(1, "enemy connected\n\n", 17);
		get_positions(positions, argv[1]);
		return (game_loop(1, p2pid, 1, positions));
	}
	if (argc == 3) {
		first_send(my_getnbr(argv[1]));
		get_positions(positions, argv[2]);
		return (game_loop(2, my_getnbr(argv[1]), 0, positions));
	}
}