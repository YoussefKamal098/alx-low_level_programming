#include "main.h"

/**
 * main - (main)
 * Description : (Description)
 * Return: (Return)
 */

int main(void)
{
    char *str = "_putchar\n";
    char *ch = str;

    while (*ch != '\0')
    {
        _putchar(*ch);
        ch++;
    }

    return (0);
}
