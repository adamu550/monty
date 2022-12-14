#include"monty.h"
/**
 * main - initializes the shell
 * @ac: number of arguments
 * @av: array of arguments
 * Return: 0 on succes.
 */

int main(int ac, char **av)
{
	FILE *file;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	_getline(file);
	return (0);
}
