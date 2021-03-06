/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** Function that prints an integer
*/

#include "navy.h"

int my_put_nbr(int nb)
{
	int val = 0;

	if (nb < 0) {
		write(1, "-", 1);
		nb = nb * (-1);
	}
	if (nb >= 0 && nb <= 9) {
		val = nb + 48;
		write(1, &val, 1);
	}
	if (nb > 9) {
		my_put_nbr(nb / 10);
		my_put_nbr(nb % 10);
	}
	return (0);
}
