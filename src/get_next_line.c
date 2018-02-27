/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** Function get_next_line.c
*/

#include "navy.h"

int nb_jumps(char *all, int opt, int fs, char *line)
{
	int i = 0;
	int nb_n = 0;

	if (opt == 1 && fs <= 0) {
		line[0] = '\0';
		return (1);
	}
	if (opt == 1)
		return (0);
	while (all[i] != '\0') {
		if (all[i] == '\n')
			nb_n = nb_n + 1;
		i = i + 1;
	}
	return (nb_n);
}

int check_space(char *all, int nb_calls, int *check, int fs)
{
	int i = 0;
	int nb_n = nb_jumps(all, 0, fs, all);
	int nb_n2 = 0;

	if (nb_calls < nb_n + 1)
		*check = 1;
	if (nb_calls == 0 && nb_n == 0)
		*check = 0;
	while (all[i] != '\0') {
		if (nb_n2 == nb_calls)
			return (i);
		if (all[i] == '\n')
			nb_n2 = nb_n2 + 1;
		i = i + 1;
	}
	if (fs <= 0)
		*check = 1;
	return (i);
}

int copy_line(char *all, char *line, int i)
{
	int j = 0;
	int k = i;

	while (all[k] != '\n' && all[k] != '\0')
		k = k + 1;
	if (all[k] == '\0') {
		line[j] = '\0';
		return (0);
	}
	while (all[i] != '\n') {
		line[j] = all[i];
		i = i + 1;
		j = j + 1;
	}
	line[j] = '\0';
	return (0);
}

void reset_it(int fd, int *nb_calls, char *all)
{
	*nb_calls = *nb_calls + 1;
	if (fd == -1) {
		all[0] = '\0';
		*nb_calls = 0;
	}
}

char *get_next_line(int fd)
{
	char *line = malloc(sizeof(char) * 1000);
	char *temp = malloc(sizeof(char) * READ_SIZE + 1);
	static char all[500000];
	static int nb_calls = 0;
	int check[4] = {0, 0, 0, -10};

	while (check[0] != 1) {
		while (nb_jumps(all, 0, 1, all) == nb_calls
		&& check[1] == 0) {
			check[3] = read(fd, temp, READ_SIZE);
			my_strcpy(all, temp, check[3]);
			check[1] = nb_jumps(all, 1, check[3], line);
		}
		check[1] = 0;
		check[2] = check_space(all, nb_calls, &check[0], check[3]);
		if (check_status(check, all, line) == 1)
			return (NULL);
	}
	reset_it(fd, &nb_calls, all);
	null_or_not(line, check[3], fd);
}
