/*
** EPITECH PROJECT, 2018
** get_next_line2.c
** File description:
** Second part of the get_next_line function
*/

#include "navy.h"

char *null_or_not(char *line, int check, int fd)
{
	if ((line[0] == '\0' && check == 0) || fd == -1) {
		return (NULL);
	} else {
		return (line);
	}
	return (line);
}

int check_status(int check[4], char *all, char *line)
{
	if (check[0] == 0 && check[3] == 0)
		return (1);
	if (check[0] == 1)
		copy_line(all, line, check[2]);
	return (0);
}