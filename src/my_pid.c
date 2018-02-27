/*
** EPITECH PROJECT, 2018
** my_pid.c
** File description:
** Function that displays the player's PID
*/

#include "navy.h"

void my_pid(void)
{
	write(1, "my_pid: ", 8);
	my_put_nbr(getpid());
	write(1, "\n", 1);
}