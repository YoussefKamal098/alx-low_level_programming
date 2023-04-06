#include "main.h"

/**
 * wildcmp - wildcmp
 * description:description
 * @s1 : @s1
 * @s2 : @s2
 * @i : @i
 * @j : @j
 * @past_star : @past_star
 * Return:return
*/

int helper(char *s1, char *s2, int i, int j, int past_star);

int found_char(char *s1, char *s2, int i, int j);

int wildcmp(char *s1, char *s2)
{
return (helper(s1, s2, 0, 0, 0));
}

/**
 * found_char - found_char
 * description:description
 * @s1 : @s1
 * @s2 : @s2
 * @i : @i
 * @j : @j
 * Return:return
*/

int found_char(char *s1, char *s2, int i, int j)
{
if (s1[i] == '\0')
return (-1);
if (s1[i] == s2[j])
return (i);
return (found_char(s1, s2, i + 1, j));
}


/**
 * helper - helper
 * description:description
 * @s1 : @s1
 * @s2 : @s2
 * @i : @i
 * @j : @j
 * @past_star : @past_star
 * Return:return
*/

int helper(char *s1, char *s2, int i, int j, int past_star)
{
if (s2[j] == '*' && s2[j + 1] == '\0')
return (1);
if (s2[j] == '*')
return (helper(s1, s2, i, j + 1, 1));
if (s1[i] == '\0' && s2[j] == '\0')
return (1);
if (s1[i] == '\0' || s2[j] == '\0')
return (0);
if (s1[i] != s2[j] && past_star)
return (helper(s1, s2, i + 1, j, 1));
if (s1[i] != s2[j])
return (0);
if (s1[i] == s2[j] && past_star)
{
if (helper(s1, s2, i + 1, j + 1, 0))
return (1);
int idx = found_char(s1, s2, i + 1, j);
if (idx != -1)
if (helper(s1, s2, idx + 1, j + 1, 0))
return (1);
return (0);
}
if (s1[i] == s2[j])
return (helper(s1, s2, i + 1, j + 1, 0));
}
