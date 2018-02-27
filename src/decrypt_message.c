/*
** EPITECH PROJECT, 2018
** decrypt_message.c
** File description:
** Function that takes the received signals and decrypt the message
*/

int reverse_bin(int mess[3])
{
	int i = 0;
	int nb = 0;

	while (i < 3) {
		if (mess[i] == 10)
			mess[i] = 0;
		if (mess[i] == 12)
			mess[i] = 1;
		i = i + 1;
	}
	nb = (mess[0] * (2 * 2)) + (mess[1] * 2) + mess[2];
	return (nb);
}

int decrypt_message(int nbsig)
{
	static int calls = 0;
	static int mess[3] = {0, 0, 0};
	static int previous = -1;

	if (nbsig > 0) {
		mess[calls] = nbsig;
		calls = calls + 1;
	}
	if (nbsig < 0) {
		mess[0] = 0;
		mess[1] = 0;
		mess[2] = 0;
		calls = 0;
	}
	if (calls == 3) {
		calls = 0;
		previous = reverse_bin(mess);
	}
	return (previous);
}