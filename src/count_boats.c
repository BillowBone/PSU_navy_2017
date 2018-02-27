/*
** EPITECH PROJECT, 2018
** count_boats.c
** File description:
** Function that verifies that there is 14 numbers on the map
*/

int is_there_boat(int position)
{
	if (position > 0)
		return (1);
	return (0);
}

int count_boats(int positions[8][8])
{
	int i = 0;
	int j = 0;
	int nb_boats = 0;

	while (i < 8) {
		while (j < 8) {
			nb_boats = nb_boats + is_there_boat(positions[i][j]);
			j = j + 1;
		}
		j = 0;
		i = i + 1;
	}
	return (nb_boats);
}