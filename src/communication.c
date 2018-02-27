/*
** EPITECH PROJECT, 2018
** communication.c
** File description:
** Function that makes the two players exchange signals
*/

#include "navy.h"

int received(int nbsig, siginfo_t *info, void *ptr)
{
	static int nb = 0;

	if (nbsig == 10 || nbsig == 12)
		nb = nbsig;
	decrypt_message(nbsig);
	return (nb);
}

int sended(int nbsig, siginfo_t *info, void *ptr)
{
	static int nb = 0;

	if (nbsig != 0)
		nb = nb + 1;
	if (nb > 3) {
		nb = 0;
		return (3);
	}
	return (nb);
}

void ready_to_kill(int *numb, int *letters, int pid)
{
	usleep(10000);
	kill(pid, letters[0]);
	usleep(10000);
	kill(pid, letters[1]);
	usleep(10000);
	kill(pid, letters[2]);
	usleep(10000);
	kill(pid, numb[0]);
	usleep(10000);
	kill(pid, numb[1]);
	usleep(10000);
	kill(pid, numb[2]);
	usleep(10000);
	free(numb);
	free(letters);
}

int send_it(int letter, int nb, int pid)
{
	int *numb = encrypt_message(nb);
	int *letters = encrypt_message(letter);
	struct sigaction action;

	action.sa_sigaction = &sended;
	action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		write(1, "Signal 1 not received\n", 22);
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		write(1, "Signal 2 not received\n", 22);
	ready_to_kill(numb, letters, pid);
	return (0);
}

int communication(void)
{
	struct sigaction action;

	action.sa_sigaction = &received;
	action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		write(1, "Signal 1 not received\n", 22);
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		write(1, "Signal 2 not received\n", 22);
	pause();
	return (decrypt_message(0));
}