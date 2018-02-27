/*
** EPITECH PROJECT, 2018
** errors.c
** File description:
** Function that checks the positions file
*/

#include "navy.h"

int good_place(char *line)
{
	if (line[1] != ':' || line[4] != ':')
		return (-1);
	if (line[0] < 50 || line[0] > 53)
		return (-1);
	if (line[3] < 49 || line[3] > 56)
		return (-1);
	if (line[6] < 49 || line[6] > 56)
		return (-1);
	if (line[2] < 65 || line[2] > 72)
		return (-1);
	if (line[5] < 65 || line[5] > 72)
		return (-1);
	if (line[2] != line[5] && line[3] != line[6])
		return (-1);
	if (line[2] == line[5] && line[3] == line[6])
		return (-1);
	return (0);
}

int no_double(char *line)
{
	static int boat[4] = {0, 0, 0, 0};

	if (line[0] == '2' && boat[0] == 1)
		return (-1);
	if (line[0] == '3' && boat[1] == 1)
		return (-1);
	if (line[0] == '4' && boat[2] == 1)
		return (-1);
	if (line[0] == '5' && boat[3] == 1)
		return (-1);
	if (line[0] == '2')
		boat[0] = 1;
	if (line[0] == '3')
		boat[1] = 1;
	if (line[0] == '4')
		boat[2] = 1;
	if (line[0] == '5')
		boat[3] = 1;
	return (0);
}

int good_line(char *line)
{
	if (my_strlen(line) != 7)
		return (-1);
	if (good_place(line) == -1)
		return (-1);
	if (no_double(line) == -1)
		return (-1);
	if ((line[2] != line[5] + (line[0] - 49)) && (line[2] != line[5])) {
		if (line[2] != line[5] - (line[0] - 49))
			return (-1);
	}
	if ((line[3] != line[6] + (line[0] - 49)) && (line[3] != line[6])) {
		if (line[3] != line[6] - (line[0] - 49))
			return (-1);
	}
	return (0);
}