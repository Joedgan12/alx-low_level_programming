#include "function_pointers.h"

/**
 * int_index - it searhes for integers in an array of integers
 * @array: te array of integers
 * @size: size of array
 * @cmp: a ponter to the function to be used to compare value
 *
 * Return: if no element matches or size <= 0 - -1
 * otherwise - the index of the first element for which
 * the cmp function does not return 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int index;

	if (array == NULL || cmp == NULL)
		return (-1);
	
	for (index = 0; index < size; index++)
	{ 
		if (cmp(array[index]) != 0)
			return (index);
	}

	return (-1);
}
