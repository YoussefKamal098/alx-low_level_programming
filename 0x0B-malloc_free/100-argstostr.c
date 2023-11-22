#include "main.h"

/**
 * argstostr - argstostr
 * @ac : ac
 * @av :av
 * Return: return
 */
char *argstostr(int ac, char **av)
{
	int i, j, nc, args_len = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);
	for (i = 0; i < ac; i++, args_len++)
		for (j = 0; av[i][j] != '\0'; j++)
			args_len += 1;
	str = (char *)malloc(args_len + 1);

	if (str == NULL)
		return (NULL);

	for (nc = 0, i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++, nc++)
			str[nc] = av[i][j];
		str[nc] = '\n';
		nc++;
	}
	str[nc] = '\0';
	return (str);
}
