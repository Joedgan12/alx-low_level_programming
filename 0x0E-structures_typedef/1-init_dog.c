#include "dog.h"
#include <stddef.h>

/**
 * init_dog - initializes dog
 * @d: pointer to dog
 * @name: dog's name
 * @age: dog's age
 * @owner: name of owner
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}

