#include "main.h"
#include <elf.h>

void puts_remaining_osabi(Elf64_Ehdr h);

/**
 * puts_magic - puts elf magic information
 * @elf: elf file struct
 */
void puts_magic(Elf64_Ehdr elf)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%2.2x%s", elf.e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");
	}
}

/**
 * puts_class - puts elf class information
 * @elf: elf file struct
 */
void puts_class(Elf64_Ehdr elf)
{
	printf("  Class:                             ");
	switch (elf.e_ident[EI_CLASS])
	{
	case ELFCLASS64:
		printf("ELF64");
		break;
	case ELFCLASS32:
		printf("ELF32");
		break;
	case ELFCLASSNONE:
		printf("none");
		break;
	}
	printf("\n");
}

/**
 * puts_data -  puts elf data information
 * @elf: elf file struct
 */
void puts_data(Elf64_Ehdr elf)
{
	printf("  Data:                              ");
	switch (elf.e_ident[EI_DATA])
	{
	case ELFDATA2MSB:
		printf("2's complement, big endian");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian");
		break;
	case ELFDATANONE:
		printf("none");
		break;
	}
	printf("\n");
}

/**
 * puts_version - puts elf version information
 * @elf: elf file struct
 */
void puts_version(Elf64_Ehdr elf)
{
	printf("  Version:                           %d", elf.e_ident[EI_VERSION]);
	switch (elf.e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)");
		break;
	case EV_NONE:
		printf("%s", "");
		break;
		break;
	}
	printf("\n");
}

/**
 * puts_osabi - puts elf osabi information
 * @elf: elf file struct
 */
void puts_osabi(Elf64_Ehdr elf)
{
	printf("  OS/ABI:                            ");
	switch (elf.e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris");
		break;
	case ELFOSABI_AIX:
		printf("UNIX - AIX");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64");
		break;
	default:
		puts_remaining_osabi(elf);
		break;
	}
	printf("\n");
}

/**
 * puts_remaining_osabi - puts elf osabi remaining information
 * in print_osabi function
 * @elf: elf file struct
 */
void puts_remaining_osabi(Elf64_Ehdr elf)
{
	switch (elf.e_ident[EI_OSABI])
	{
	case ELFOSABI_MODESTO:
		printf("Novell - Modesto");
		break;
	case ELFOSABI_OPENBSD:
		printf("UNIX - OpenBSD");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App");
		break;
	case ELFOSABI_ARM:
		printf("ARM");
		break;
	default:
		printf("<unknown: %x>", elf.e_ident[EI_OSABI]);
		break;
	}
}

/**
 * puts_abiversion  - puts elf abiversion information
 * @elf: elf file struct
 */
void puts_abiversion(Elf64_Ehdr elf)
{
	printf("  ABI Version:                       %d\n",
	       elf.e_ident[EI_ABIVERSION]);
}

/**
 * puts_type - puts elf type information
 * @elf: elf file struct
 */
void puts_type(Elf64_Ehdr elf)
{
	char *ptr = (char *)&elf.e_type;
	int i = 0;

	printf("  Type:                              ");

	if (elf.e_ident[EI_DATA] == ELFDATA2MSB)
		i = 1;

	switch (ptr[i])
	{
	case ET_NONE:
		printf("NONE (None)");
		break;
	case ET_REL:
		printf("REL (Relocatable file)");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)");
		break;
	case ET_CORE:
		printf("CORE (Core file)");
		break;
	default:
		printf("<unknown>: %x", ptr[i]);
		break;
	}
	printf("\n");
}

/**
 * puts_entry - puts elf entry information
 * @elf: elf file struct
 */
void puts_entry(Elf64_Ehdr elf)
{
	int i = 0, length = 0;
	unsigned char *ptr = (unsigned char *)&elf.e_entry;

	printf("  Entry point address:               0x");
	if (elf.e_ident[EI_DATA] != ELFDATA2MSB)
	{
		i = elf.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!ptr[i])
		{
			i--;
		}
		printf("%x", ptr[i--]);
		while (i >= 0)
		{
			printf("%02x", ptr[i]);
			i--;
		}
		printf("\n");
	}
	else
	{
		length = elf.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		i = 0;
		while (!ptr[i])
		{
			i++;
		}
		printf("%x", ptr[i++]);
		while (i <= length)
		{
			printf("%02x", ptr[i]);
			i++;
		}
		printf("\n");
	}
}

/**
 * is_elf_file - is the file elf file
 * @elf: elf file struct
 * Return: 1 if condition true 0 otherwise
 */

int is_elf_file(Elf64_Ehdr elf)
{
	return (elf.e_ident[0] == 0x7f && elf.e_ident[1] == 'E' &&
		elf.e_ident[2] == 'L' && elf.e_ident[3] == 'F');
}

/**
 * puts_elf_file_info - puts elf file information
 * @elf:elf file struct
 */

void puts_elf_file_info(Elf64_Ehdr elf)
{
	puts_magic(elf);
	puts_class(elf);
	puts_data(elf);
	puts_version(elf);
	puts_osabi(elf);
	puts_abiversion(elf);
	puts_type(elf);
	puts_entry(elf);
}

/**
 * main - main
 * @argc: argc
 * @args: args
 * Return: 1 on success 0 on failure
 */
int main(int argc, char **args)
{
	int file_descriptor;
	Elf64_Ehdr elf;
	ssize_t bytes;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	file_descriptor = open(args[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		dprintf(STDERR_FILENO, "Can't open file: %s\n", args[1]);
		exit(98);
	}

	bytes = read(file_descriptor, &elf, sizeof(elf));
	if (bytes < 1 || bytes != sizeof(elf))
	{
		dprintf(STDERR_FILENO, "Can't read from file: %s\n", args[1]);
		exit(98);
	}

	if (is_elf_file(elf))
	{
		printf("ELF Header:\n");
	}
	else
	{
		dprintf(STDERR_FILENO, "Not ELF file: %s\n", args[1]);
		exit(98);
	}

	puts_elf_file_info(elf);

	if (close(file_descriptor))
	{
		dprintf(STDERR_FILENO, "Error closing file descriptor: %d\n",
			file_descriptor);
		exit(98);
	}

	return (EXIT_SUCCESS);
}
