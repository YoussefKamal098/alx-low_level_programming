#include "main.h"

/**
 * is_number - is_number
 * @s: s
 * Return: return
 */
int is_number(char *s)
{
	int i;

	if (*s == '-')
		s++;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] > '9' || s[i] < '0')
			return (0);
	}

	return (1);
}

/**
 * _memset - _memset
 * @ptr: ptr
 * @val: val
 * @size: size
 * Return: return
 */

char *_memset(void *ptr, int val, unsigned int size)
{
	char *p;

	if (ptr == NULL)
		return (NULL);

	p = ptr;

	while (size--)
		*p++ = val;

	return (ptr);
}

/**
 * _strlen - _strlen
 * @s: s
 * Return: return
 */
unsigned int _strlen(char *s)
{
	int i;

	if (s == NULL || *s == '\0')
		return (0);

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}

/**
 * get_sign - get_sign
 * @num1: num1
 * @num2: num2
 * Return: return
 */

int get_sign(char *num1, char *num2)
{
	int sign = 1;

	if (*num1 == '-')
		sign *= -1;
	if (*num2 == '-')
		sign *= -1;

	return (sign);
}

/**
 * get_result_len - get_result_len
 * @num1: num1
 * @num2: num2
 * Return: return
 */

int get_result_len(char *num1, char *num2)
{
	int num1_len = _strlen(*num1 == '-' ? num1 + 1 : num1);
	int num2_len = _strlen(*num2 == '-' ? num2 + 1 : num2);
	int sign = get_sign(num1, num2), result_len;

	result_len = num1_len + num2_len;

	if (sign == -1)
		result_len++;

	return (result_len);
}

/**
 * multiply - multiply
 * @num1: num1
 * @num2: num2
 * Return: return
 */

char *multiply(char *num1, char *num2)
{
	int num1_len = _strlen(num1);
	int num2_len = _strlen(num2);
	int result_len = get_result_len(num1, num2);
	int carry, pro;
	int shift = 0, d_pos;
	int sign = get_sign(num1, num2);
	char *res = (char *)malloc(result_len + 1);
	int i, j;

	if (res == NULL)
		return (NULL);
	_memset(res, '0', result_len);
	res[result_len] = '\0';
	for (i = num1_len - 1; i >= 0 && num1[i] != '-'; --i)
	{
		carry = 0;
		shift++;
		d_pos = result_len - shift;
		for (j = num2_len - 1; j >= 0 && num2[j] != '-'; --j)
		{
			pro = (num1[i] - '0') * (num2[j] - '0') + (res[d_pos] - '0') + carry;
			res[d_pos] = (pro % 10) + '0';
			carry = pro / 10;
			d_pos--;
		}
		res[d_pos] += carry;
	}
	if (sign == -1)
	{
		if (carry == 0)
			res[1] = '-';
		else
			res[0] = '-';
	}
	return (res);
}

/**
 * _puts - _puts
 * @str : @str
 * Return:return
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}

/**
 * is_zero -  is_zero
 * @str : @str
 * Return:return
 */

int is_zero(char *str)
{
	int i;

	if (*str == '-')
		str++;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != '0')
			return (0);
	}

	return (1);
}

/**
 * main - main
 * @ac: ac
 * @av:av
 * Return: return
 */

int main(int ac, char *av[])
{
	char *res;
	int i = 0;

	if (ac != 3 || !is_number(av[1]) || !is_number(av[2]))
	{
		_puts("Error\n");
		exit(98);
	}

	if (av[1][0] == '\0' || av[2][0] == '\0')
	{
		_puts("Error\n");
		exit(98);
	}

	if (is_zero(av[1]) || is_zero(av[2]))
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}

	res = multiply(av[1], av[2]);

	if (res == NULL)
	{
		_puts("Error\n");
		exit(98);
	}

	while (res[i] == '0')
		++i;

	_puts(res + i);
	_putchar('\n');

	free(res);

	return (0);
}

