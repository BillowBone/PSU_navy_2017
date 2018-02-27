/*
** EPITECH PROJECT, 2018
** count_hits.c
** File description:
** Function that counts the number of hitted boats
*/

#include "navy.h"

int is_it_hitted(int nb)
{
	if (nb == -1) {
		return (1);
	} else {
		return (0);
	}
}

int count_hits(int map[8][8])
{
	int i = 0;
	int j = 0;
	int hits = 0;

	while (i < 8) {
		while (j < 8) {
			hits = hits + is_it_hitted(map[i][j]);
			j = j + 1;
		}
		j = 0;
		i = i + 1;
	}
	return (hits);
}