#include "dog.h"

/**
 * init_dog -init_dog
 * @d: d
 * @name: name
 * @age: age
 * @owner: owner
 * Return: return
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		return;

	d->name = name;
	d->age = age;
	d->owner = owner;
}
