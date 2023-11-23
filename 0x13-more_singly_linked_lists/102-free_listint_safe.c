#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_len(const listint_t *head);

/**
 * looped_listint_len - in our looped listint_t linked list the 
 * 	unique nodes are counted
 * @head: check head of listint_t pointer
 *
 * Return: not looped list - 0
 * Otherwise - show number of unique nodes in list
 */

size_t looped_listint_len(const listint_t *head)
{
	const listint_t *marion, *ruth;
	size_t optimus = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	marion = head->next;
	ruth = (head->next)->next;

	while (ruth)
	{
		if (marion == ruth)
		{
			marion = head;
			while (marion != ruth)
			{
				optimus++;
				marion = marion->next;
				ruth = ruth->next;
			}

			marion = marion->next;
			while (marion != ruth)
			{
				optimus++;
				marion = marion->next;
			}

			return (optimus);
		}

		marion = marion->next;
		ruth = (ruth->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - safely print listint_t
 * @head: head of liistint_t list pointer
 *
 * Return: number of nodes in list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t optimus, ind = 0;

	optimus = looped_listint_len(head);
	
	if (optimus == 0)
	{
		for (; head != NULL; optimus++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (ind = 0; ind < optimus; ind++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (optimus);
}

