#include "sort.h"

/**
 *intercambiador_shell - intercambia ints
 *@i: int 1
 *@j: int 2
 *Return: void
 */
void intercambiador_shell(int *array, size_t intervalo, size_t size, size_t list)
{
	int conf;
	int a;
	size_t b;
	size_t temporal;


	for (b = list; b < size; b += intervalo)
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
 *shell_sort -
 *@array:
 *@size:
 *Return
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
