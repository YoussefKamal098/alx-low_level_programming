#include "function_pointers.h"

/**
 * print_name -print_name
 * description:description
 * @f : f
 * @name : bane
 * Return:return
 */

void print_name(char *name, void (*f)(char *))
{
if (name && f)
f(name);
}
