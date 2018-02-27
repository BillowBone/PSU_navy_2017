/*
** EPITECH PROJECT, 2018
** manage_args.c
** File description:
** Functions that manages my arguments
*/

#include "navy.h"

int good_nb_boats(char *str, char *line)
{
	int positions[8][8];

	free(line);
	get_positions(positions, str);
	if (count_boats(positions) != 14)
		return (-1);
	return (0);
}

int good_text(char *str)
{
	int fd = open(str, O_RDONLY);
	int i = 0;
	char *line;

	if (fd == -1)
		return (84);
	while (i < 4) {
		line = get_next_line(fd);
		if (line == NULL)
			return (84);
		if (good_line(line) == -1)
			return (84);
		i = i + 1;
	}
	if (get_next_line(fd) != NULL)
		return (84);
	close(fd);
	if (good_nb_boats(str, line) == -1)
		return (84);
	return (0);
}

void print_usage(void)
{
	write(1, "USAGE\n     ./navy [first_player_pid] navy_positions\n", 52);
	write(1, "DESCRIPTION\n     first_player_pid: ", 35);
	write(1, "only for the 2nd player. pid of the first player.\n", 50);
	write(1, "     navy_positions: file representing the positions", 52);
	write(1, " of the ships.\n", 15);
}

int manage_p2(int argc, char *argv[])
{
	if (argc == 3) {
		if (my_str_isnum(argv[1]) == 0)
			return (84);
		if (good_text(argv[2]) == 0) {
			return (0);
		} else {
			write(1, "Invalid positions\n", 18);
			return (84);
		}
	} else {
		write(1, "Too much arguments, check ./navy -h\n", 36);
		return (84);
	}
}

int manage_args(int argc, char *argv[])
{
	if (argc == 1) {
		write(1, "Not enough arguments, check ./navy -h\n", 38);
		return (84);
	}
	if (argc == 2) {
		if (my_strcmp(argv[1], "-h") == 0) {
			print_usage();
			return (0);
		}
		if (good_text(argv[1]) == 0) {
			return (0);
		} else {
			write(1, "Invalid positions\n", 18);
			return (84);
		}
	}
	return (manage_p2(argc, argv));
}