#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void close_elf(int elf);
void print_type(unsigned int e_type, unsigned char *e_ident);

/**
 * check_elf - confirm if file is an ELF file
 * @e_ident: pointer to an array that contains ELF numbers
 *
 * Description: not ELF file - exit code 98
 */
void check_elf(unsigned char *e_ident)
{
	int ind;

	for (ind = 0; ind < 4; ind++)
	{
		if (e_ident[ind] != 127 && e_ident[ind] != 'E' && e_ident[ind] != 'L' && e_ident[ind] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - magic numbers of ELF header are printed
 * @e_ident: array that contains ELF numers its pointer
 *
 * Description: spaces separate magic numbers
 */
void print_magic(unsigned char *e_ident)
{
	int ind;

	printf("Magic:");

	for (ind = 0; ind < EI_NIDENT; ind++)
	{
		printf("%02x", e_ident[ind]);

		if (ind == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}
/**
 * print_class - class of ELF header is printed
 * @e_ident: pointer to arrat containing ELF class
 */
void print_class(unsigned char *e_ident)
{
	printf("Class:");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<nknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * print_data - we print data of ELF header
 * @_ident: pointer to an array having ELF class
 */
void print_data(unsigned char *e_ident)
{
	printf(" Data: ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's compliment, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's compliment, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * print_version - version of ELF header is printed
 * @e_ident: pointer to array containing ELF version
 */
void print_version(unsigned char *e_ident)
{
	printf("Version: %d", e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf("(current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}
/**
 * print_osabi - printing OS/ABI of ELF header
 * @e_ident: pointer to array containg ELF version
 */
void print_osabi(unsigned char *e_ident)
{
	printf("OS/ABI: ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}
/**
 * print_abi - printing ABI version of ELF header
 * @e_ident: pointer to an array of ELF ABI version
 */
void print_abi(unsigned char *e_ident)
{
	printf("ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}
/**
 * print_type - type of ELF header is printed
 * @e_type: type of ELF
 * @e_ident: pointer to an array containing ELF Class
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("Type: ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}
/**
 * print_entry - printing entry point of ELF header
 * @e_entry: entry point of ELF address
 * @e_ident: pointer to array containing ELF class
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("Entry point address: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}
/**
 * close_elf - close ELF file
 * @elf: descriptor file of ELF file
 *
 * Description: file cannot be closed - exit code 98
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
}
/**
 * main - information in ELF header at the beginningof ELF file
 * is displayed
 * @argc: arguments in the program
 * @argv: array of pointers to the argument
 *
 * Return: success(0)
 *
 * Description: if file not function/ELF file - exit code 98
 */
int main(int __attribute__((__unused__))argc, char *argv[])
{
	Elf64_Ehdr *header;
	int no, yes;

	no = open(argv[1], O_RDONLY);
	if (no == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file%s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(no);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	yes = read(no, header, sizeof(Elf64_Ehdr));
	if (yes == -1)
	{
		free(header);
		close_elf(no);
		dprintf(STDERR_FILENO, "Error: %s: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(no);
	return (0);
}
