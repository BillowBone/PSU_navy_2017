/*
** EPITECH PROJECT, 2018
** get_positions.c
** File description:
** Function that put the positions in an int array
*/

#include "navy.h"

void initialize(int positions[8][8])
{
	int i = 0;
	int j = 0;

	while (i < 8) {
		while (j < 8) {
			positions[i][j] = 0;
			j = j + 1;
		}
		j = 0;
		i = i + 1;
	}
}

void good_positions(char *line)
{
	char temp;

	if (line[2] == line[5] && line[6] < line[3]) {
		temp = line[3];
		line[3] = line[6];
		line[6] = temp;
	}
	if (line[3] == line[6] && line[5] < line[2]) {
		temp = line[2];
		line[2] = line[5];
		line[5] = temp;
	}
}

void put_positions(char *line, int positions[8][8])
{
	int i = line[0] - 48;
	int j = 0;
	int k = 0;

	good_positions(line);
	j = line[3] - 49;
	k = line[2] - 65;
	while (i > 0) {
		positions[j][k] = line[0] - 48;
		if (line[2] == line[5])
			j = j + 1;
		if (line[3] == line[6])
			k = k + 1;
		i = i - 1;
	}
}

void get_positions(int positions[8][8], char *file)
{
	int fd = open(file, O_RDONLY);
	int i = 0;
	char *line;

	get_next_line(-1);
	initialize(positions);
	while (i < 4) {
		line = get_next_line(fd);
		put_positions(line, positions);
		i = i + 1;
	}
	close(fd);
	free(line);
}