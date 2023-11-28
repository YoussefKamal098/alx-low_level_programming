#include "dog.h"

/**
 * _strlen - _strlen
 * @str: str
 * Return: return
 */

size_t _strlen(char *str)
{
	size_t i;

	if (str == NULL)
		return (0);

	for (i = 0; str[i]; i++)
		;
	return (i);
}

/**
 * _strdup - _strdup
 * @str: str
 * Return: return
 */

char *_strdup(char *str)
{
	int i;
	char *dup_str;

	if (str == NULL)
		return (NULL);

	dup_str = (char *)malloc(_strlen(str) + 1);

	if (dup_str == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		dup_str[i] = str[i];

	dup_str[i] = '\0';

	return (dup_str);
}

/**
 * new_dog - new_dog
 * @name: name
 * @age: age
 * @owner: owner
 * Return: return
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog = (dog_t *)malloc(sizeof(dog_t));
	char *name_cpy, *owner_cpy;

	if (dog == NULL || age < 0 || name == NULL || owner == NULL)
		return (NULL);

	name_cpy = _strdup(name);

	if (name_cpy == NULL)
	{
		free(dog);
		return (NULL);
	}

	dog->name = name_cpy;

	owner_cpy = _strdup(owner);

	if (owner_cpy == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}

	dog->owner = owner_cpy;
	dog->age = age;

	return (dog);
}
