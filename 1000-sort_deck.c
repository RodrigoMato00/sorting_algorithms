#include "deck.h"

/**
 *_compara_str - compara la suma ascii de caracteres en dos strings
 *@comp1: string 1
 *@comp2: string 2
 *Return: 0 si son iguales, 1 si comp1 es mayor, -1 si comp2 es mayor
 */
int _compara_str(char *comp1, char *comp2)
{
	int a = 0, b = 0;

	while (comp1[a] != '\0')
	{
		if (comp1[a] > comp2[a])
		{
			b = comp1[a] - comp2[a];
			break;
		}

		else if (comp1[a] < comp2[a])
		{
			b = comp1[a] - comp2[a];
			break;
		}

		a++;
	}

	if (comp2[a] != '\0' && b == 0)
	{
		b = -comp2[a];
	}
	return (b);
}

/**
 * ace_to_king - reemplaza el valor de la carta de as a 10
 * @carta1: card comapred
 * @carta2: card comapred
 * Return: 0
 */
short ace_to_king(deck_node_t *carta1, deck_node_t *carta2)
{
	short i = 0;
	short aux1 = -1;
	short aux2 = -1;
	char *numero_cartas[] = {"Ace", "1", "2", "3", "4", "5", "6", "7",
				 "8", "9", "10", "Jack", "Queen", "King"};

	if (carta1->card->kind != carta2->card->kind)
	{
		return (0);
	}

	while ((aux1 == -1 || aux2 == -1) && i < 14)
	{
		if (!_compara_str((char *)carta1->card->value,
				  numero_cartas[i]))
		{
			aux1 = i;
		}

		if (!_compara_str((char *)carta2->card->value,
				  numero_cartas[i]))
		{
			aux2 = i;
		}
		i++;
	}

	if ((aux1 > aux2) && aux1 >= 0 && aux2 >= 0)
	{
		return (1);
	}

	return (0);
}

/**
 * sort_deck - sort the deck
 * @deck: pointer to the first node of the deck
 * Return: void
 */
void sort_deck(deck_node_t **deck)
{
	char cambia;
	deck_node_t *iterador;
	deck_node_t *temporal;

	iterador = *deck;
	cambia = 1;

	while (cambia)
	{
		cambia = 0;
		while (iterador->next)
		{
			temporal = iterador->next;
			if (iterador->card->kind > temporal->card->kind
			    || ace_to_king(iterador, temporal))
			{
				cambia = 1;
				if (*deck == iterador)
				{
					*deck = temporal;
				}
				iterador->next = temporal->next;
				if (temporal->next)
				{
					temporal->next->prev = iterador;
				}

				temporal->next = iterador;
				temporal->prev = iterador->prev;
				if (iterador->prev)
				{
					iterador->prev->next = temporal;
				}
				iterador->prev = temporal;
				continue;
			}
			iterador = iterador->next;
		}
		iterador = *deck;
	}
}
