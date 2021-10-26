#include "sort.h"

/**
 *countador_de_digitos - counts the digits of a number
 *@i: number to count
 *Return: number of digits
 */
int countador_de_digitos(int i)
{
	int number = 0;
	int n_dig = i;

	do {
		number++;
		n_dig = n_dig / 10;
	} while (n_dig != 0);
		;

	return (number);
}

/**
 *_potencia - returns the power of a number
 *@a: number to count
 *@b: power
 *Return: number of digits
 */
int _potencia(int a, int b)
{
	if (b == 0)
	{
		return (1);
	}

	else if (b < 0)
	{
		return (-1);
	}

	return (a * _potencia(a, b - 1));
}

/**
 * buscador_de_digitos - finds the digits of a number
 * @c: number to find
 * @posicion: number of digits
 * Return: number of digits
 */
int buscador_de_digitos(int c, int posicion)
{
	int resultado;
	int expo;

	expo = _potencia(10, posicion - 1);
	resultado = (c / expo) % 10;

	return (resultado);
}

/**
 *continuacion_radix - sorts an array of integers in ascending order
 *@array: array to sort
 *@size: size of the array
*@d_max: maximum number of array
*@contenedor: array to store the sorted array
 */
void continuacion_radix(int *array, int *contenedor, int size, int d_max)
{
	int *array_a_ordenar;
	int iterador;
	int contador, digito;

	array_a_ordenar = malloc(sizeof(int) * size);
	if (array_a_ordenar == NULL)
	{
		free(contenedor);
		return;
	}
	for (iterador = 1; iterador <= d_max; iterador++)
	{
		for (contador = 0; contador < 10; contador++)
		{
			contenedor[contador] = 0;
		}
		for (contador = 0; contador < size; contador++)
		{
			digito = buscador_de_digitos(array[contador], iterador);
			contenedor[digito] += 1;
		}
		for (contador = 1; contador < 10; contador++)
		{
			contenedor[contador] += contenedor[contador - 1];
		}
		for (contador = (size - 1); contador >= 0; contador--)
		{
			digito = buscador_de_digitos(array[contador], iterador);
			array_a_ordenar[contenedor[digito] - 1] = array[contador];
			contenedor[digito] -= 1;
		}
		for (contador = 0; contador < size; contador++)
		{
			array[contador] = array_a_ordenar[contador];
		}
		print_array(array, size);
	}
	free(contenedor);
	free(array_a_ordenar);
}

/**
 *radix_sort - sorts an array of integers in ascending
 *order using radix sort algorithm
 *@array: array to sort
 *@size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int *contenedor;
	int d_max, d_ac_nu;
	int size_num, contador;

	d_max = 0;
	size_num = (int) size;

	if (array == NULL || size < 2)
	{
		return;
	}

	contenedor = malloc(sizeof(int) * 10);

	if (contenedor == NULL)
	{
		return;
	}

	for (contador = 0; contador < 10; contador++)
	{
		contenedor[contador] = 0;
	}

	for (contador = 0; contador < size_num; contador++)
	{
		d_ac_nu = countador_de_digitos(array[contador]);
		if (d_ac_nu > d_max)
			d_max = d_ac_nu;
	}

	continuacion_radix(array, contenedor, size_num, d_max);
}
