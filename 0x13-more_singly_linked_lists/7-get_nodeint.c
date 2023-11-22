#include "lists.h"

/**
 * get_nodeint_at_index - in a linked list node is returned at a certain index
 * @head: linked list first node
 * @index: index of node to return
 *
 * Return: pointer to the node. or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int x = 0;
	listint_t *mag = head;

	while (mag && x < index)
	{
		mag = mag->next;
		x++;
	}

	return (mag ? mag : NULL);
}
