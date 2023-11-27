#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - allocate 1024 bytes for buffer
 * @file: name of file buffer storing chars
 *
 * Return: pointer to the new allocated buffer
 */
char *create_buffer(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buff);
}

/**
 * close_file - file descriptors closed
 * @fd: fle descriptor to be closed
 */
void close_file(int fd)
{
	int k;

	k = close(fd);
	if (k == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - contents of a file are copied to another
 * @argc: number of arguments
 * @argv: array of pointers to arguments
 *
 * Return: success (0)
 *
 * Description: argument incorrect - exit code 97
 * if file_from cannot be read - exit code 98
 * if file_to cannot be created - exit code 99
 * if file_to or file_from can't be closed- exit code 100
 */
int main(int argc, char *argv[])
{
	int mid, op, j, q;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = create_buffer(argv[2]);
	mid = open(argv[1], O_RDONLY);
	j = read(mid, buff, 1024);
	op = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (mid == -1 || j == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		q = write(op, buff, j);
		if (op == -1 || q == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		j = read(mid, buff, 1024);
		op = open(argv[2], O_WRONLY | O_APPEND);
	} while (j > 0);

	free(buff);
	close_file(mid);
	close_file(op);

	return (0);
}
