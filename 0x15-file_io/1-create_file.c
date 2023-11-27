#include "main.h"

/**
 * create_file - create file
 * @filename: name of file to be created pointer
 * @text_content: string to be written to file pointer
 *
 * Return: fail (-1)
 * otherwise (1)
 */
int create_file(const char *filename, char *text_content)
{
	int l, m, n = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (n = 0; text_content[n];)
			n++;
	}
	l = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	m = write(l, text_content, n);

	if (l == -1 || m == -1)
		return (-1);

	close(l);
	return (1);
}
