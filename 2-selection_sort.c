#include "sort.h"

/**
 *selection_sort - sorts an array of integers in ascending
 *order using the Selection sort algorithm
 *@array: random number array
 *@size: array size
 *Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t a;
	size_t b;
	size_t minimo;
	int temporal = 0;

	if (!size || size == 1)
		return;

	for (a = 0; a < size; a++)
	{

		b = a + 1;
		minimo = a;

		for (b = a + 1; b < size; b++)
		{

			if (array[minimo] > array[b])
				minimo = b;

		}

		if (minimo != a)
		{

			temporal = array[a];
			array[a] = array[minimo];
			array[minimo] = temporal;
			print_array(array, size);

		}
	}
}
