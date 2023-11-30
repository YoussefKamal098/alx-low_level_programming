#include "function_pointers.h"

/**
 * main - main
 * @ac: ac
 * @av: av
 * Return: return
 */

int main(int ac, char *av[])
{
	char *p = (char *)main;
	int b;

	if (ac != 2)
		printf("Error\n"), exit(1);

	b = atoi(av[1]);

	if (b < 0)
		printf("Error\n"), exit(2);

	while (b--)
		printf("%02hhx%s", *p++, b ? " " : "\n");

	return (0);
}
