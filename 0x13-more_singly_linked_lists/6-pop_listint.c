#include "lists.h"

/**
 * pop_listint - in linked list head node is deleted
 * @head: pointer to the first element in linked list
 *
 * Return: data that was deleted inside the elements
 * zero if list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *mug;
	int jag;

	if (!head || !*head)
		return (0);

	jag = (*head)->n;
	mug = (*head)->next;
	free(*head);
	*head = mug;

	return (jag);
}
