#include "main.h"

/**
 * flip_bits - bits to change we count to get
 * from a number to another
 * @n: 1st number
 * @m: 2nd number
 *
 * Return: bits to be changed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int op, mag = 0;
	unsigned long int temp;
	unsigned long int tall = n ^ m;

	for (op = 63; op >= 0; op--)
	{
		temp = tall >> op;
		if (temp & 1)
			mag++;
	}

	return (mag);
}
