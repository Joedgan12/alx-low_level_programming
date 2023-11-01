#include <stdio.h>
/**
 * main - prints the number of arguments passed into it
 * @argc: nmber of command line argument
 * @argv: arrray that contains the proram command line arg
 * Return: (0) when successful
 */
int main(int argc, char **argv __attribute__((unused)))
{
	printf("%d\n", argc - 1);
	return (0);
}
