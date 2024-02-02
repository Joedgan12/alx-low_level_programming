#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to a hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head = ht;
	hash_node_t *nodes, *top;
	unsigned long int joe;

	for (joe = 0; joe < ht->size; joe++)
	{
		if (ht->array[joe] != NULL)
		{
			nodes = ht->array[joe];
			while (nodes != NULL)
			{
				top = nodes->next;
				free(nodes->key);
				free(nodes->value);
				free(nodes);
				nodes = top;
			}
		}
	}
	free(head->array);
	free(head);
}
