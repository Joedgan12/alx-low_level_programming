#include "main.h"

/**
 * append_text_to_file - text at the end of file is appended
 * @filename: name of file its pointer
 * @text_content: string to add to the end of file
 *
 * Return: fail (-1)
 * file doesn't exist the user lacks write permission (-1)
 * otherwise (1)
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int hen, cow, mag = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (mag = 0; text_content[mag];)
			mag++;
	}

	hen = open(filename, O_WRONLY | O_APPEND);
	cow = write(hen, text_content, mag);

	if (hen == -1 || cow == -1)
		return (-1);

	close(hen);

	return (1);
}
