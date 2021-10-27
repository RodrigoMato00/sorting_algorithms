#include "sort.h"


/**
 *div_array - divides the array
 *@array: array to be divided
 *@init: initial index
 *@fin: final index
 *@size: size of the array
 *Return: size of the array
 */
int div_array(int *array, int init, int fin, size_t size)
{
	int aux1, aux2;
	int temporal;
	int pivot;

	aux1 = init - 1;
	aux2 = fin + 1;
	pivot = array[fin];

		while (1)
		{
		do {
			aux1++;
		} while (array[aux1] < pivot)
			;
		do {
			aux2--;
		} while (array[aux2] > pivot)
			;

		if (aux1 < aux2)
		{
			temporal = array[aux1];
			array[aux1] = array[aux2];
			array[aux2] = temporal;

			print_array(array, size);
		}

		else
		{
			return (aux1);
		}
	}
}

/**
 *hoare_rec - recursive function to interact
 *@array: array a ordenar
 *@size: size of array
 *@min: min of array
 *@max: max of array
 *Return: void
 */
void hoare_rec(int *array, int min, int max, size_t size)
{
	 int pivot;

	if (min < max)
	{
		pivot = div_array(array, min, max, size);
		hoare_rec(array, min, pivot - 1, size);
		hoare_rec(array, pivot, max, size);

	}
}

/**
 *quick_sort_hoare - sorts an array of integers in ascending order
 *@array: array to be sorted
 *@size: size of the array
 *Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{

	hoare_rec(array, 0, size - 1, size);

}
