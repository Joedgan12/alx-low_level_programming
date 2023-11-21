#include "lists.h"

/**
 * free_listint - linked list is freed
 * @head: listint_t list to be freed
 */
void free_listint(listint_t *head)
{
	listint_t *mug;

	while (head)
	{
		mug = head->next;
		free(head);
		head = mug;
	}
}

