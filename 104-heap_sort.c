#include "sort.h"

/**
 */
void intercambiador_int(int *i, int *j, size_t size, int *array_1)
{
	int temporal;

	temporal = *i;
	*i = *j;
	*j = temporal;

	print_array(array_1, size);
}

/**
 *heap_value - cambiar los valores en funcion de la pila
 */
void heap_value(int *array_1, size_t init, size_t i, size_t size)
{
	size_t a , b , c;

	a = 0;
	c = 0;
	b = 0;

	a = init;
	while (2 * a + 1 <= i)
	{
		b = 2 * a + 1;
		c = a;

		if (array_1[c] < array_1[b])
		{
			c = b;
		}

		if (b + 1 <= i && array_1[c] < array_1[b + 1])
		{
			c = b + 1;
		}

	        if (c == a)
		{
			return;
		}
		else if (a != c)
		{
			intercambiador_int(&array_1[a], &array_1[c], size, array_1);
			a = c;
		}
	}

}
/**
 *array_to_heap - pasa un array a una pila
 */
void array_to_heap(int *array_1, size_t size)
{
	size_t init;

	init = 0;

	init = (size - 2) / 2;
	while (init > 0)
	{
		heap_value(array_1, (size_t)init, size - 1, size);
		if (init)
		{
			init--;
		}

		else
		{
			break;
		}
	}
}

/**
 *heap_sort - heap sort
 */
void heap_sort(int *array, size_t size)
{
	size_t i = 0;

	if (size < 2)
	{
		return;
	}

	array_to_heap(array, size);
	i = size - 1;
	while (i)
	{
		if (i)
		{
			intercambiador_int(&array[0], &array[i], size, array);
		}

		i--;
		heap_value(array, 0, i, size);
	}
}
