#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - print read text tile to STDOUT
 * @filename: read text file
 * @letters: read number of letters
 * Return: w- print actual number of bytes read
 * when function fails or filename is NULL(0)
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *naf;
	ssize_t h;
	ssize_t x;
	ssize_t j;

	h = open(filename, O_RDONLY);
	if (h == -1)
		return (0);
	naf = malloc(sizeof(char) * letters);
	j = read(h, naf, letters);
	x = write(STDOUT_FILENO, naf, j);

	free(naf);
	close(h);
	return (x);
}
