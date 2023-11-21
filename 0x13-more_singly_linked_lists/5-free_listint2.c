#include "lists.h"

/**
 * free_listint2 - linked list freed
 * @head: pointer to the listint_t is to be freed
 */
void free_listint2(listint_t **head)
{
	listint_t *mug;

	if (head == NULL)
		return;

	while (*head)
	{
		mug = (*head)->next;
		free(*head);
		*head = mug;
	}

	*head = NULL;
}
