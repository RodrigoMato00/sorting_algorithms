#include "sort.h"
#include <stdbool.h>

/**
 *intercambiador_int - intercambia ints
 *@i: change 1
 *@j: change 2
 *Return: void
 */
void intercambiador_int(int *i, int *j)
{
	int temporal;

	temporal = *i;
	*i = *j;
	*j = temporal;
}

/**
 *bubble_sort - bubble sort
 *@array: random number array
 *@size: array size
 *Return: void
 **/
void bubble_sort(int *array, size_t size)
{
	size_t len = size;
	size_t contador;
	bool boo = false;

	if (array == NULL || size < 2)
		return;

	while (boo == false)
	{
		boo = true;

		for (contador = 0; contador < len - 1; contador++)
		{

			if (array[contador] > array[contador + 1])
			{

				intercambiador_int(array + contador,
						   array + contador + 1);
				print_array(array, size);
				boo = false;
			}
		}
		len--;
	}
}
