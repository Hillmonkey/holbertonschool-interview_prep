#include "lists.h"


/**
 * check_cycle - determines if there is a cycle in a singly linked list
 * @list: struct of type list_int_t
 * Return: int, 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *turtle, *hare;
	int status = 2; /* 0= no cycle, 1 = is cycle, 2 = continue */

	turtle = hare = list;

	while (status == 2)
	{
		if (turtle->next)
			turtle = turtle->next;
		else if (hare->next)
		{
			hare = hare->next;
			if (hare == turtle)
				status = 1;
			else if (hare->next == NULL)
				status = 0;
			else
			{
				hare = hare->next;
				if (hare == turtle)
					status = 1;
				else if (hare->next  == NULL)
					status = 0;
			}
		}
		else
			status = 0;
	}
	return status;
}
