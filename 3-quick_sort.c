#include "sort.h"

/**
 *part_array - partition array
 *@lo: change 1
 *@hi: chagne 2
 *@array: random number array
 *@size: array size
 *Return: the value of the pivot
 */
int part_array(int *array, int lo, int hi, size_t size)
{
	int a, b;
	int temporal, pivot;

	pivot = array[hi];

	for (b = lo, a = lo - 1; b < hi; b++)
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

	if (array[hi] != array[a + 1])
		print_array(array, size);

	return (a + 1);
}

/**
 *ordenando_rec - ordenando_rec
 *@i: smallest integer of partition
 *@j: integer of partition
 *@array: random number array
 * @size: array size
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
 *quick_sort - sorts an array of integers in
 *ascending order using the Quick sort algorithm
 *@array: random number array
 *@size: array size
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
