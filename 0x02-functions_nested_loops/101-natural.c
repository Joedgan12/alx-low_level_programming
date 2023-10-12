#include <stdio.h>
/**
 * main - function to summultiples of 3 or 5 in numbers below 1024
 * Return: 0
 */

int main(void)
{
	int sum = 0;
	int i;

	for (i = 0 ; i < 1024 ; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
			sum = sum + 1;
	}
	printf("%d\n", sum);
	return (0);
}
