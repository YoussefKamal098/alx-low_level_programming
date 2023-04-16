#include <stdio.h>
#include <stdlib.h>

/**
 * main- main
 * description:description
 * @argc : @argc
 * @argv : @argv
 * Return:return
 */
int main(int argc, char *argv[])
{
if (argc == 2)
{
int i, least_cents = 0, money = atoi(argv[1]);
int cents[] = {25, 10, 5, 2, 1};

for (i = 0; i < 5; i++)
{
if (money >= cents[i])
{
least_cents += money / cents[i];
money = money % cents[i];
if (money % cents[i] == 0)
{
break;
}
}
}

printf("%d\n", least_cents);
}
else
{
printf("Error\n");
return (1);
}
return (0);
}
