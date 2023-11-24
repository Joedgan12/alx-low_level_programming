#include "main.h"

/**
 * set_bit - bit is set at index 1
 * @n: number to change it's pointer
 * @index: index of bit to be set to 1
 *
 * Return: void(-1), success (1)
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
