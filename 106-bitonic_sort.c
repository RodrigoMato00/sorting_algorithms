#include "sort.h"

/**
 *orden - sort the values of an array with respectto the bitonic sort algorithm
 *@array: array to be sorted
 *@size: size of the array
 *@arr:check if the array is sorted
 * Return: void
 */
void orden(char arr, int *array, size_t size)
{
	size_t i, j;
	int mov;

	j = size / 2;
	for (i = 0; i < j; i++)
	{
		if ((array[i] > array[i + j]) == arr)
		{
			mov = array[i];
			array[i] = array[i + j];
			array[i + j] = mov;
		}
	}
}
/**
 * merge_array - funcion que fusiona dos arrays, es recursiva
 * @array: fusion to array
 * @size: size of the array
 * @arr:check if the array is sorted
 */
void merge_array(char arr, int *array, size_t size)
{
	if (size < 2)
	{
		return;
	}

	orden(arr, array, size);
	merge_array(arr, array, size / 2);
	merge_array(arr, array + (size / 2), size / 2);
}

/**
 *bitonic_recursivo - sort the values of an array with respectto
*the bitonic sort algorithm
 *@array: array to be sorted
 *@size: size of the array
 *@i:size
 *@arr:check if the array is sorted
 */
void bitonic_recursivo(char arr, int *array, size_t size, size_t i)
{
	if (size < 2)
	{
		return;
	}

	printf("Merging [%lu/%lu] (%s):\n", size, i, (arr == 1) ? "UP" : "DOWN");
	print_array(array, size);

	bitonic_recursivo(1, array, size / 2, i);

	bitonic_recursivo(0, array + (size / 2), size / 2, i);

	merge_array(arr, array, size);

	printf("Result [%lu/%lu] (%s):\n", size, i, (arr == 1) ? "UP" : "DOWN");
	print_array(array, size);

}

/**
 *bitonic_sort - sort the values of an array with respectto
 *@array: array sorted
 *@size: size of the array
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
	bitonic_recursivo(1, array, size, size);
}
