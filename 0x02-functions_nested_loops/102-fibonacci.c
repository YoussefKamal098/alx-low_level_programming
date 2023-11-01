#include "main.h"
/**
 * main - main
 * Return: return
 */
int main(void)
{
	long i, t1 = 0, t2 = 1, sum;

	for (i = 0; i < 50; i++)
	{
		sum = t1 + t2;
		printf("%lu", sum);

		t1 = t2;
		t2 = sum;

		if (i == 49)
		{
			printf("\n");
		}
		else
		{
			printf(", ");
		}
	}

	return (0);
}
