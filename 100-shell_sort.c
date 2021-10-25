#include "sort.h"

/**
 *intercambiador_shell - intercambia ints
 *@array: array
 *@l: l
 *@size: size
 *@intervalo: intervalo
 *Return: void
 */
void intercambiador_shell(int *array, size_t l, size_t size, size_t intervalo)
{
	int conf;
	int a;
	size_t b;
	size_t temporal;

	for (b = l; b < size; b += intervalo)
	{
		for (a = b; a >= 0; a -= intervalo)
		{
			conf = a - intervalo;
			if (array[conf] > array[a])
			{
				temporal = array[a];
				if (conf >= 0)
				{
					array[a] = array[conf];
					array[conf] = temporal;
				}
			}
		}
	}
}

/**
 *shell_sort - orts an array of integers in ascending
 *order using the Shell sort algorithm, using the Knuth sequence
 *@array: array
 *@size: size
 *Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t intervalo;
	size_t contador;

	intervalo = 1;

	if (!array || size < 2)
		return;

	for (contador = 0; contador < size; contador = ((contador * 3) + 1))
	{
		if (contador < size)
			intervalo = contador;
	}
	for (; intervalo >= 1; intervalo = ((intervalo - 1) / 3))
	{
		for (contador = 0; contador < size; contador++)
		{
			intercambiador_shell(array, contador, size, intervalo);
		}
		print_array(array, size);
	}
}
