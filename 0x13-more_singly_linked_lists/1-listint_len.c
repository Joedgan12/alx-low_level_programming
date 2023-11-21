#include "lists.h"

/**
 * listint_len - linked lists returns number of elements
 * @h: linked list of tpe listint_t to cover
 *
 * Return: node numbers
 */
size_t listint_len(const listint_t *h)
{
	size_t tem = 0;

	while (h)
	{
		tem++;
		h = h->next;
	}

	return (tem);
}
