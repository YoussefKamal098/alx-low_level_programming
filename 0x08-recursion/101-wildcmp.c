#include "main.h"
/**
 * helper - helper
 * @s1: s1
 * @s2: s2
 * @i: i
 * @j: j
 * Return: 0 or 1
 */

int helper(char *s1, char *s2, int i, int j)
{
	if (s2[j] != '*')
	{
		if (s1[i] != s2[j])
			return (0);

		if (s1[i] == '\0')
			return (1);

		return (helper(s1, s2, i + 1, j + 1));
	}

	while (s2[j] == '*')
		j++;

	if (s1[i] == '\0' && s2[j] == '\0')
		return (1);
	while (1)
	{

		if (s1[i] == '\0' && s2[j] == '\0')
			return (1);

		if (s1[i] == s2[j])
			if (helper(s1, s2, i + 1, j + 1))
				return (1);

		if (s1[i] == '\0')
			break;

		i++;
	}

	return (0);
}

/**
 * wildcmp - wildcmp
 * @s1: s1
 * @s2: s2
 * Return: 0 or 1
 */

int wildcmp(char *s1, char *s2)
{
	return (helper(s1, s2, 0, 0));
}
