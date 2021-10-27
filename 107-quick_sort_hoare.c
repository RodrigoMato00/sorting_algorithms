#include "sort.h"


/**
 *div_array - parte el arrey
 *@arrey: array a partir
 *@init: inicio del array
 *@fin: final del array
 *@size: tamano de arrey a partir
 *Return: tamano
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
		do
		{
			aux1++;
		}
		while (array[aux1] < pivot)
			;
		do
		{
			aux2--;
		}
		while (array[aux2] > pivot)
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
 *hoare_rec - funcion recursiva con parametros para ordenar
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
 */
void quick_sort_hoare(int *array, size_t size)
{

	hoare_rec(array, 0, size - 1, size);

}
