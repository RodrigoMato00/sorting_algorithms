#include "sort.h"

/**
 *nodo_intercambiador - nodo intercambiador
 *@c: c
 *@m: m
 *Return: void
 */
void nodo_intercambiador(listint_t **c, unsigned char m)
{
	listint_t *temporal0, *temporal1;

	temporal0 = NULL;
	temporal1 = NULL;
	if (m == 0)
	{
		temporal0 = (*c)->prev;
		if (temporal0)
			temporal1 = temporal0->prev
		if ((*c)->next)
			(*c)->next->prev = temporal0;
		temporal0->next = (*c)->next;
		temporal0->prev = *c;
		(*c)->next = temporal0;
		(*c)->prev = temporal1;
		if (temporal1)
			temporal1->next = *c;
		*c = temporal0;
	}
	else if (m == 1)
	{
		temporal0 = (*c)->next;
		if (temporal0)
			temporal1 = temporal0->next;
		if ((*c)->prev)
			(*c)->prev->next = temporal0;
		temporal0->prev = (*c)->prev;
		temporal0->next = *c;
		(*c)->prev = temporal0;
		(*c)->next = temporal1;
		if (temporal1)
			temporal1->prev = *c;
		*c = temporal0;
	}
}

/**
 *cocktail_sort_list - sorts a doubly linked list of integers in ascending
 *order using the Cocktail shaker sort algorithm
 *@list: list
 *Return:void
 */
void cocktail_sort_list(listint_t **list)
{
	unsigned char j;
	listint_t *c;
	listint_t *c2;

	j = 1;
	if (!list || !(*list) || !((*list)->next))
		return;

	while (j)
	{
		j = 0;
		for (c = *list; c; c = c->next)
		{
			if (c->prev && (c->prev->n > c->n))
			{
				j = 1;
				nodo_intercambiador(&c, 0);

				if (!c->prev->prev)
					*list = c->prev;
				print_list(*list);
			}

			if (c->next == NULL)
				c2 = c;
		}
		for (; c2; c2 = c2->prev)
		{

			if (c2->next && (c2->next->n < c2->n))
			{
				j = 1;
				nodo_intercambiador(&c2, 1);

				if (c2->prev == NULL)
					*list = c2;
				print_list(*list);
			}
		}
	}
}
