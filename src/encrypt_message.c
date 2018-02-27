/*
** EPITECH PROJECT, 2018
** encrypt_message.c
** File description:
** Function that encrypt my messages to be transmitted by signals
*/

#include "navy.h"

int *encrypt_message(int nb)
{
	int *mess = malloc(sizeof(int) * 4);
	int modulo = 0;
	int i = 2;

	if (nb < 0 || nb > 7)
		return (-1);
	mess[3] = -1;
	while (i >= 0) {
		modulo = nb % 2;
		if (modulo == 0) {
			mess[i] = 10;
		} else {
			mess[i] = 12;
		}
		if (nb == 1)
			nb = 0;
		nb = nb / 2;
		i = i - 1;
	}
	return (mess);
}