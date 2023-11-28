#include "dog.h"

/**
 * free_dog -free_dog
 * @d: d
 * Return: return
 */

void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	if (d->name)
		free(d->name);
	if (d->owner)
		free(d->owner);
	free(d);
}
