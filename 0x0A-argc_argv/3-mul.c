#include <stdio.h>

/**
 * main - multiples two numbers
 * @argc: number of command line arg
 * @argv: the aray that contains the command line arg
 * Return: (0) if successful
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	printf("%d\n", atoi(argv[1]) * atoi(argv[2]));
	return (0);
}
