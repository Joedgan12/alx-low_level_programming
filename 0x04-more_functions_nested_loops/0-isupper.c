#include "main.h"
/**
 * _isupper -prog checks for uppercase character
 * @c: Variable text
 * Return: always 0
 */
int _isupper(int c)
{
if (c >= 'A' && c <= 'Z')
{
return (1);
}
else
{
return (0);
}
}
