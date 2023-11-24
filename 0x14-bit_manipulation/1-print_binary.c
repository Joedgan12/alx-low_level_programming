#include "main.h"

/**
 * print_binary - binary same as decimal numbers is printed
 * @n: number in binary
 */
void print_binary(unsigned long int n)
{
	int jam, cnt = 0;
	unsigned long int kilo;

	for (jam = 63; jam >= 0; jam--)
	{
		kilo = n >> jam;

		if (kilo & 1)
		{
			_putchar('1');
			cnt++;
		}
		else if (cnt)
			_putchar('0');
	}
	if (!cnt)
		_putchar ('0');
}
