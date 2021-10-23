#include "sort.h"

/**
 *part_array - partition array
 *@i: i
 *@j: j
 *@array: array
 *@size: size
 *Return: el valor del pivot
 */
int part_array(int *array, int i, int j, size_t size)
{
	int a, b;
	int temporal, pivot;

	pivot = array[j];

	for (b = i, a = i - 1; b < j; b++)
	{

		if (array[b] < pivot)
		{

			a++;
			temporal = array[a];
			array[a] = array[b];
			array[b] = temporal;
			if (array[a] != array[b])
				print_array(array, size);

		}
	}

	temporal = array[a + 1];
	array[a + 1] = pivot;
	array[b] = temporal;

	if (array[j] != array[a + 1])
		print_array(array, size);

	return (a + 1);
}

/**
 *ordenando_rec - ordenando_rec
 *@i: ind inferior de la particion
 *@j: ind de la particion
 *@array: array
 * @size: size
 *Return: void
 */
void ordenando_rec(int *array, int i, int j, size_t size)
{
	int pivot;

	if (i < j)
	{

		pivot = part_array(array, i, j, size);
		ordenando_rec(array, i, pivot - 1, size);
		ordenando_rec(array, pivot + 1, j, size);

	}
}

/**
 *quick_sort - orts an array of integers in
 *ascending order using the Quick sort algorithm
 *@array: array
 *@size: size
 *Return: void
 */
void quick_sort(int *array, size_t size)
{
	{
		if (!array)
			return;
		ordenando_rec(array, 0, size - 1, size);
	}
}
