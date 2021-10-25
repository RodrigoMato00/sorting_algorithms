#include "sort.h"

/**
 *
 *
 *
 *
 *
 */
void print_merge(int *array, int *p1, int *p2, size_t size)
{
	int a = 0;
	int b = 0;
	int c = 0;
	int size_p1 = size / 2;
	int size_p2 = size - size_p1;

	while (a < size_p1 && b < size_p2)
	{

		if (p1[a] < p2[b])
		{
			array[c++] = p1[a++];
		}

      		else
		{
			array[c++] = p2[b++];
		}

	}

	while (a < size_p1)
	{
		array[c++] = p1[a++];
	}

	while (b < size_p2)
	{
		array[c++] = p2[b++];
	}

	printf("Merging...\n");

        printf("[left]: ");
	print_array(p1, size_p1);

	printf("[right]: ");
	print_array(p2, size_p2);

	printf("[Done]: ");
	print_array(array, size);
}

/**
 *
 *
 *
 *
 */
void merge_sort(int *array, size_t size)
{
	int *izquierda, *derecha;
	size_t centro;
	size_t aux;

	int aux_pos[10];

	if (array == NULL || size < 2)
	{
		return;
	}

	centro = size / 2;
	izquierda = aux_pos;
	derecha = &aux_pos[centro];

	for (aux = 0; aux < centro; aux++)
	{
		izquierda[aux] = array[aux];
	}

	for (aux = centro; aux < size; aux++)
	{
		derecha[aux - centro] = array[aux];
	}

	merge_sort(izquierda, centro);

	merge_sort(derecha, size - centro);

	print_merge(array, izquierda, derecha, size);
}
