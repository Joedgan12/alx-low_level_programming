#include "main.h"

/**
 * binary_to_uint - unsigned int is converted from binary
 * @b: string contains binary number
 *
 * Return: number
 */

unsigned int binary_to_uint(const char *b)
{
	int p;
	unsigned int crac = 0;

	if (!b)
		return (0);

	for (p = 0; b[p]; p++)
	{
		if (b[p] < '0' || b[p] > '1')
			return (0);
		crac = 2 * crac + (b[p] - '0');
	}

	return (crac);
}
