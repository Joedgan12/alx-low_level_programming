#include "lists.h"

/**
 * sum_listint - all data in listint_t list calculate sum
 * @head: first node in linked list
 *
 * Return: sum result
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *mag = head;

	while (mag)
	{
		sum += mag->n;
		mag = mag->next;
	}

	return (sum);
}
