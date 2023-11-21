#include "lists.h"

/**
 * add_nodeint - beginning of a linked list a new node is added
 * @head: pointer to th first node in the list
 * @n: new node insert data
 *
 * Return: NULL if it fails or pointer to new node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}
