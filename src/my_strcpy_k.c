/*
** EPITECH PROJECT, 2018
** my_strcpy_k.c
** File description:
** Ameliorated version of my_strcpy
*/

#include "navy.h"

void my_strcpy(char *str, char *str2, int k)
{
	int i = 0;
	int j = 0;

	str2[k] = '\0';
	while (str[i] != '\0') {
		i = i + 1;
	}
	while (str2[j] != '\0') {
		str[i] = str2[j];
		i = i + 1;
		j = j + 1;
	}
	str[i] = '\0';
}