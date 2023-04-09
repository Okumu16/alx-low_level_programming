#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "main.h"
#define BUFFER_SIZE 1024
/**
 * main- copies the content of a file to another
 * @argc: the number of arguments passed to the program
 * @argv: an array of the arguments passed to the program
 * Return: 0
*/

int main(int argc, char *argv[])
{
int fd_from, fd_to, ret;
char buffer[BUFFER_SIZE];

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
exit(97);
}

/*open file_from for reading*/
fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}
fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
if (fd_to == -1)
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
exit(99);
while ((ret = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
if (write(fd_to, buffer, ret) != ret)
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
exit(99);
}
if (ret == -1)
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
if (close(fd_from) == -1)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
exit(100);
if (close(fd_to) == -1)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
exit(100);

return (0);
}
