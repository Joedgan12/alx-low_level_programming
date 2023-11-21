#include "lists.h"

/**
 * print_listint - linked list elements are printed
 * @h: print linked list of type listint
 *
 * Return: node numbers
 */
size_t print_listint(const listint_t *h)
{
	size_t tem = 0;

	while(h)
	{
		printf("%d\n", h->n);
		tem++;
		h = h->next;
	}

	return (tem);
}
