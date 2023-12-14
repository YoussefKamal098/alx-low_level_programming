#include "main.h"

int helper(char *s1, char *s2, int i, int j);

/**
 * skip_stars - skip_stars
 * @s: s
 * @i: i
 * Return: 0 or 1
 */

int skip_stars(char *s, int i)
{
	if (s[i] == '*')
		return (skip_stars(s, i + 1));

	return (i);
}

/**
 * compare - compare
 * @s1: s1
 * @s2: s2
 * @i: i
 * @j: j
 * Return: 0 or 1
 */

int compare(char *s1, char *s2, int i, int j)
{
	if (s1[i] == '\0' && s2[j] == '\0')
		return (1);

	if (s1[i] == s2[j])
		if (helper(s1, s2, i + 1, j + 1))
			return (1);
	if (s1[i] == '\0')
		return (0);

	if (compare(s1, s2, i + 1, j))
		return (1);

	return (0);
}

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

	j = skip_stars(s2, j);

	if (s1[i] == '\0' && s2[j] == '\0')
		return (1);

	return (compare(s1, s2, i, j));
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
