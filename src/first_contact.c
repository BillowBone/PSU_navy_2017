/*
** EPITECH PROJECT, 2018
** first_contact.c
** File description:
** Functions that makes the two players connect
*/

#include "navy.h"

int well_received(int nbsig, siginfo_t *info, void *ptr)
{
	static int pid = 0;

	if (nbsig == SIGUSR1) {
		pid = (int)info->si_pid;
		return (1);
	}
	if (nbsig == 0)
		return (pid);
	return (0);
}

int well_sended(int nbsig, siginfo_t *info, void *ptr)
{
	if (nbsig == SIGUSR1) {
		write(1, "successfully connected\n\n", 24);
		return (1);
	}
	return (0);
}

int first_received(void)
{
	struct sigaction action;

	action.sa_sigaction = &well_received;
	action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		write(1, "Reception failed\n", 17);
	pause();
	usleep(10000);
	if (kill(well_received(0, NULL, NULL), SIGUSR1) == -1)
		write(1, "Signal not sent\n", 16);
	usleep(10000);
	return (well_received(0, NULL, NULL));
}

int first_send(int pid)
{
	struct sigaction action;

	kill (pid, SIGUSR1);
	action.sa_sigaction = &well_sended;
	action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		write(1, "Reception failed\n", 17);
	pause();
	return (0);
}