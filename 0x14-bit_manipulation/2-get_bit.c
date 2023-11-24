#include "main.h"

/**
 * get_bit - bit at an index in a decimal is returned
 * @n: number
 * @index: index of bit
 * Return: bit value
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int val_bit;

	if (index > 63)
		return (-1);

	val_bit = (n >> index) & 1;

	return (val_bit);
}
