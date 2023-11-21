#include "lists.h"

/**
 * add_nodeint_end -- linked list node is added at the end
 * @head: pointer to the first element on the list
 * @n: new element data is inserted
 *
 * Return: pointer to new node, or NULL ifit fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;
	listint_t *mug = *head;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	while (mug->next)
		mug = mug->next;

	mug->next = new;

	return (new);
}
