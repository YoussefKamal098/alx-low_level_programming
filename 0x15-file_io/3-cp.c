#include "main.h"

#define USAGE "Usage: cp file_from file_to\n"
#define ERR_READ "Error: Can't read from file %s\n"
#define ERR_WRITE "Error: Can't write to %s\n"
#define ERR_ClOSE "Error: Can't close fd %d\n"
#define PERMISSION (S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IROTH)

/**
 * main- main
 * @argc : @argc
 * @argv : @argv
 * Description:description
 * Return:return
 */

int main(int argc, char **argv)
{
int from_fd = 0, to_fd = 0;
char buffer[BUFFER_SIZE];
ssize_t bytes;

if (argc != 3)
dprintf(STDERR_FILENO, USAGE), exit(97);

from_fd = open(argv[1], O_RDONLY);

if (from_fd == -1)
dprintf(STDERR_FILENO, ERR_READ, argv[1]), exit(98);

to_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, PERMISSION);

if (to_fd == -1)
dprintf(STDERR_FILENO, ERR_WRITE, argv[2]), exit(99);

while ((bytes = read(from_fd, buffer, BUFFER_SIZE)) > 0)
if (write(to_fd, buffer, bytes) != bytes)
dprintf(STDERR_FILENO, ERR_WRITE, argv[2]), exit(99);

if (bytes == -1)
dprintf(STDERR_FILENO, ERR_READ, argv[1]), exit(100);

close(from_fd);
close(to_fd);

if (from_fd)
dprintf(STDERR_FILENO, ERR_ClOSE, argv[1]), exit(100);

if (to_fd)
dprintf(STDERR_FILENO, ERR_ClOSE, argv[2]), exit(100);

return (EXIT_SUCCESS);
}
