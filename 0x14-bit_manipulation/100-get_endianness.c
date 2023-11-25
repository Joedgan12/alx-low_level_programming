#include "main.h"

/**
 * get_endianness - little or big endia
 * Return: little (1), big (0)
 */
int get_endianness(void)
{
	unsigned int lemon = 1;
	char *c = (char *) &lemon;

	return (*c);
}
