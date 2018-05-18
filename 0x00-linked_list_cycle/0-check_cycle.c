#include "lists.h"


/**
 * check_cycle - determines if there is a cycle in a singly linked list
 * @list: struct of type list_int_t
 * Return: int, 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *turtle, *hare;

	turtle = hare = list;
	if (list && list->next && list->next->next)
	{
		turtle = list->next;
		hare = list->next->next;
	}
	else
		return (0);
	while (1)
	{
		if (turtle->next)
			turtle = turtle->next;
		else
			return (0);
		if (hare->next)
		{
			hare = hare->next;
			if (hare == turtle)
				return (1);
			if (hare->next == NULL)
				return (0);
			hare = hare->next;
			if (hare == turtle)
				return (1);
			if (hare->next  == NULL)
				return (0);
		}
		else
			return (0);
	}
}
