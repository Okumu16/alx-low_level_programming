#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * read_textfile- reads a text file and prints
 * it to the POSIX standard output
 * @filename: name of the file
 * @letters: number of letters it could read
 * Return: actual number of letters
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd = open(filename, O_RDONLY);
char *buffer = (char *) malloc(sizeof(char) * (letters + 1));
ssize_t bytes_read = read(fd, buffer, letters);
ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);


if (filename == NULL)
return (0);

if (fd == -1)
return (0);

if (buffer == NULL)
return (0);

if (bytes_read == -1)
{
free(buffer);
close(fd);
return (0);
}

buffer[bytes_read] = '\0';


if (bytes_written == -1 || bytes_written != bytes_read)
{
free(buffer);
close(fd);
return (0);
}

free(buffer);
close(fd);
return (bytes_read);
}