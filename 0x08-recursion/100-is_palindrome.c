#include "main.h"

/**
 * is_palindrome - is_palindrome
 * description:description
 * @s : @s
 * @i : @i
 * @j : @j
 * Return:return
*/

int helper(char *s, int i, int j);

int is_palindrome(char *s)
{
return (helper(s, 0, strlen(s) - 1));
}

/**
 * helper - helper
 * description:description
  * @s : @s
 * @i : @i
 * @j : @j
 * Return:return
*/


int helper(char *s, int i, int j)
{
if (i >= j)
return (1);
if (s[i] != s[j])
return (0);
return (helper(s, i + 1, j - 1));
}
