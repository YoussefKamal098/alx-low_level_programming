#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - generates keygen for crackme5
 * @ac: number of arguments passed to the program
 * @av: array of strings passed to the program
 * Return: always 0
 */
int main(int ac, char *av[])
{
	char password[7], *code;
	int length = strlen(av[1]), i, tmp;

	(void)ac;
	code = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	tmp = (length ^ 59) & 63;
	password[0] = code[tmp];

	tmp = 0;
	for (i = 0; i < length; i++)
		tmp += av[1][i];
	password[1] = code[(tmp ^ 79) & 63];

	tmp = 1;
	for (i = 0; i < length; i++)
		tmp *= av[1][i];
	password[2] = code[(tmp ^ 85) & 63];

	tmp = 0;
	for (i = 0; i < length; i++)
	{
		if (av[1][i] > tmp)
			tmp = av[1][i];
	}
	srand(tmp ^ 14);
	password[3] = code[rand() & 63];

	tmp = 0;
	for (i = 0; i < length; i++)
		tmp += (av[1][i] * av[1][i]);
	password[4] = code[(tmp ^ 239) & 63];

	for (i = 0; i < av[1][0]; i++)
		tmp = rand();

	password[5] = code[(tmp ^ 229) & 63];
	password[6] = '\0';
	printf("%s", password);
	return (0);
}
