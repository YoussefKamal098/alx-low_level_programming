#include <stdio.h>

/**
 * main- main
 * description:description
 * @argc : @argc
 * @argv : @argv
 * Return:return
 */

int main(int argc, char *argv[])
{
	int i;
	(void)argc;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}
