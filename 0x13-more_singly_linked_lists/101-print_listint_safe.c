#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_len(const listint_t *head);

/**
 * looped_listint_len - nodes that are unique are counted in the
 * looped listint_t linked list
 * @head: check pointer to the head of listint_t
 *
 * Return: list not looped - 0
 * Otherwise - unique number of nodes in the list
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *nikes, *jordans;
	size_t node = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	nikes = head->next;
	jordans = (head->next)->next;

	while (jordans)
	{
		if (nikes == jordans)
		{
			nikes = head;
			while (nikes != jordans)
			{
				node++;
				nikes = nikes->next;

				jordans = jordans->next;
			}

			nikes = nikes->next;
			while (nikes != jordans)
			{
				node++;
				nikes = nikes->next;
			}
			
			return (node);
		}

		nikes = nikes->next;
		jordans = (jordans->next)->next;
	}

	return (0);
}
/**
 * print_listint_safe - safely we print listint_t list
 * @head: head of thee listint_t list pointer
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t node, ind = 0;
	
	node = looped_listint_len(head);

	if (node == 0)
	{
		for (; head != NULL; node++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (ind = 0; ind < node; ind++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (node);
}
