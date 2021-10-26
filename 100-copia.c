#include "sort.h"

/**
 *shell_sort - shell sort
 *@size: size of elements
 *@array: array
 *Return: void
 */
void shell_sort(int *array, size_t size)
{
	unsigned int in, out, i = 1;
	int tmp;

	if (size < 2)
		return;

	while (i <= size / 3)
		i = i * 3 + 1;

	while (i > 0)
	{
		for (out = i; out < size; out++)
		{
			tmp = array[out];
			in = out;

			while (in > i - 1 && array[in - i] >= tmp)
			{
				array[in] = array[in - i];
				in = in - i;
			}

			array[in] = tmp;
		}

		i = (i - 1) / 3;

		print_array(array, size);
	}
}