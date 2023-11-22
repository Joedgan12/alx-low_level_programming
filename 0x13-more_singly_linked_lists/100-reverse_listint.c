#include "lists.h"

/**
 * reverse_listint - linked list is reversed
 * @head: first node in the list pointer
 *
 * Return: pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *before = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = before;
		before = *head;
		*head = next;
	}

	*head = before;

	return (*head);
}
