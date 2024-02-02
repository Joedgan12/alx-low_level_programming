#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table.
 * @size: The size of the array.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *them;
	unsigned long int joe;

	them = malloc(sizeof(hash_table_t));
	if (them == NULL)
		return (NULL);

	them->size = size;
	them->array = malloc(sizeof(hash_node_t *) * size);
	if (them->array == NULL)
		return (NULL);
	for (joe = 0; joe < size; joe++)
		them->array[joe] = NULL;

	return (them);
}
