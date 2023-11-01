#include "main.h"
#include <stdio.h>

/**
 * _putchar - writes the character c to stdout
 * @c: Ther character toprint
 *
 * Return: on success 1
 * on error, -1 is returned 
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
