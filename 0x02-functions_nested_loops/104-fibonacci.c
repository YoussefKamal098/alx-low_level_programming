#include "main.h"

/**
 * num_length - num_length
 * @num : num
 * Return: return
 */

int num_length(int num)
{
	int length = 0;

	if (!num)
	{
		return (1);
	}

	while (num)
	{
		num = num / 10;
		length += 1;
	}

	return (length);
}

/**
 * main - main
 * Return: return
 */
int main(void)
{
	int i, initial0s;
	long t1 = 1, t2 = 2, sum, max = 100000000, f1 = 0, f2 = 0, sumo = 0;

	for (i = 1; i <= 98; i++)
	{
		if (f1 > 0)
		{
			printf("%l", f1);
		}

		initial0s = num_length(max) - 1 - num_length(t1);

		while (f1 > 0 && initial0s > 0)
		{
			printf("%d", 0);
			initial0s--;
		}

		printf("%l", t1);

		sum = (t1 + t2) % max;
		sumo = f1 + f2 + (t1 + t2) / max;
		t1 = t2;
		f1 = f2;
		t2 = sum;
		f2 = sumo;

		if (i != 98)
		{
			printf(", ");
		}
		else
		{
			printf("\n");
		}
	}

	return (0);
}
