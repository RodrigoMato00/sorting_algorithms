#include "sort.h"

/**
 *insertion_sort_list - sorts a doubly linked list of integers
 *in ascending order using the Insertion sort algorithm
 *@list: random number list
 *Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i;
	listint_t *j;

	if (!list || !(*list) || !(*list)->next)
		return;

	i = *list;
	while (i)
	{
		j = i;

		while (j->prev && j->n < j->prev->n)
		{
			j->prev->next = j->next;

			if (j->next)
			{

				j->next->prev = j->prev;

			}

			j->next = j->prev;
			j->prev = j->prev->prev;
			j->next->prev = j;

			if (!j->prev)

				*list = j;

			else

				j->prev->next = j;
			print_list(*list);
		}
		i = i->next;
	}
}
