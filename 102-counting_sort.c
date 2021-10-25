#include "sort.h"

/**
 *count_array - count array
 *@array: random number array
 *@i: changer
 *@size: array size
 *Return: co_ar
 */
int *count_array(int *array, size_t i, size_t size)
{
	size_t pos;
	int *co_ar;

	co_ar = malloc(sizeof(int) * (i + 1));

	if (!co_ar)
		return (NULL);

	for (pos = 0; pos < i + 1; pos++)
	{

		co_ar[pos] = 0;

	}

	for (pos = 0; pos < size; pos++)
	{

		co_ar[array[pos]] += 1;

	}

	for (pos = 0; pos < i; pos++)
	{

		co_ar[pos + 1] += co_ar[pos];

	}
	return (co_ar);
}

/**
 *counting_sort - counting sort
 *@array: random number array
 *@size: array size
 *Return: void
 */
void counting_sort(int *array, size_t size)
{
	size_t mov;
	int a, b;
	int *co_ar, *aux;

	if (!array || size < 2)
		return;

	b = array[0];
	for (mov = 0; mov < size; mov++)
	{

		if (b < array[mov])
			b = array[mov];

	}

	co_ar = count_array(array, b, size);
	print_array(co_ar, b + 1);

	aux = malloc(sizeof(int) * size);
	if (!aux)
		return;

	for (mov = 0 ; mov < size; mov++)
	{

		a = array[mov];
		aux[co_ar[a] - 1] = a;
		co_ar[a]--;

	}

	for (mov = 0; mov < size; mov++)
		array[mov] = aux[mov];

	free(co_ar);
	free(aux);
}
