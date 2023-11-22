#include "lists.h"

/**
 * free_listint_safe - linked list is freed
 * @h: first node in the linked list pointer
 *
 * Return: element nmbers in the freed list
 */
size_t free_listint_safe(listint_t *h)
{
	size_t kit = 0;
	int diff;
	listint_t *mag;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		diff = *h - (*h)->next;
		if (diff > 0)
		{
			mag = (*h)->next;
			free(*h);
			*h = mag;
			kit++;
		}
		else
		{
			free(*h);
			*h = NULL;
			kit++;
			break;
		}
	}
	
	*h = NULL;

	return (kit);
}

