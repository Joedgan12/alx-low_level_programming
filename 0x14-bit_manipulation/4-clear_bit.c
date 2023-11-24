#include "main.h"

/**
 * clear_bit - value of any bit is set to zero
 * @n: number to change
 * @index: bit to clear
 *
 * Return: void (0)
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
