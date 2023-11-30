#include "3-calc.h"

/**
 * main - main
 * @ac: ac
 * @av: av
 * Return: return
 */

int main(int ac, char *av[])
{
	int a, b, (*op_func)(int, int);

	if (ac != 4)
		printf("Error\n"), exit(98);

	a = atoi(av[1]);
	b = atoi(av[3]);

	op_func = get_op_func(av[2]);

	if (!op_func)
		printf("Error\n"), exit(99);

	if (!b && (av[2][0] == '/' || av[2][0] == '%'))
		printf("Error\n"), exit(100);

	printf("%d\n", op_func(a, b));

	return (0);
}

