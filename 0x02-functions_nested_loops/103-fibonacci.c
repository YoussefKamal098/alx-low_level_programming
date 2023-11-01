#include "main.h"
/**
 * main - main
 * Return: return
 */
int main(void)
{
	long i, t1 = 0, t2 = 1, sum;
	float total_sum;

	while (1)
	{
		sum = t1 + t2;

		if (sum > 4000000)
		{
			break;
		}

		if (sum % 2 == 0)
		{
			total_sum += sum;
		}

		t1 = t2;
		t2 = sum;
	}

	printf("%.0f\n", total_sum);

	return (0);
}
