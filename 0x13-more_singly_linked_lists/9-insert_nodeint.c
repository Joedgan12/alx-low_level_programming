#include "lists.h"

/**
 * insert_nodeint_at_index - at a given position new node is 
 * inserted in linked list
 * @head: pointer to first node in the list
 * @idx: index where new node is added
 * @n: data to insert in new node
 *
 * Return: pointer to new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int p;
	listint_t *new;
	listint_t *mag = *head;

	new = malloc(sizeof(listint_t));
	if (!new || !head)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	for (p = 0; mag && p < idx; p++)
	{
		if (p == idx - 1)
		{
			new->next = mag->next;
			mag->next = new;
			return (new);
		}
		else
			mag = mag->next;
	}

	return (NULL);
}
