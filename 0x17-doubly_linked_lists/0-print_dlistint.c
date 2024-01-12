#include "lists.h"

/**
 * print_dlistint - all elements of dlistint_t list
 * are printed
 *
 * @h: head of list
 * Return: number of nodes
 */
size_t print_slistint(const dlistint_t *h)
{
	int count;

	count = 0;

	if (h == NULL)
		return (count);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}

	return (count);
}
