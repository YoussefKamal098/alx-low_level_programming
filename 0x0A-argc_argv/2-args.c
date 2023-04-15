#include <stdio.h>

/**
 * main- main
 * description:description
 * @argc : @argc
 * @argv : @argv
 * Return:return
 */

int main(int argc, int *argv[])
{int i;
(void)argc;

for (i = 0; i < sizeof(argv) / sizeof(argv[0]); i++)
{
printf("%s\n", argv[i]);
}

return (0);
}
