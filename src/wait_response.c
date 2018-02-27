/*
** EPITECH PROJECT, 2018
** wait_response.c
** File description:
** Function that wait for the other user to tell if he's hit or not
*/

#include "navy.h"

int response(int nbsig, siginfo_t *info, void *ptr)
{
	static int nb = 0;

	if (nbsig != 0)
		nb = nbsig;
	return (nb);
}

void wait_response(void)
{
	struct sigaction action;

	action.sa_sigaction = &response;
	action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		write(1, "Signal 1 not received\n", 22);
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		write(1, "Signal 2 not received\n", 22);
	pause();
}

void analyse_response(int *coord, int enemy[8][8])
{
	if (response(0, NULL, NULL) == SIGUSR2) {
		write(1, "hit\n\n", 5);
		enemy[coord[1]][coord[0]] = -1;
	} else {
		write(1, "missed\n\n", 8);
		if (enemy[coord[1]][coord[0]] != -1)
			enemy[coord[1]][coord[0]] = -2;
	}
}