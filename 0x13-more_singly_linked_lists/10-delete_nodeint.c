#include "lists.h"

/**delete_nodeint_at_index - nodes in a linked list at an index are deleted
 * @head: first element in the list its pointer
 * @index: index of node to be deleted
 *
 * Return: success(1) or fail (-1)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *mag = *head;
	listint_t *today = NULL;
	unsigned int x = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(mag);
		return (1);
	}

	while (x < index - 1)
	{
		if (!mag || !(mag->next))
			return (-1);
		mag = mag->next;
		x++;
	}

	today = mag->next;
	mag->next = today->next;
	free(today);

	return (1);
}
