#include "main.h"
#define BUFFER_SIZE 1024

/**
 * error_message- prints custom error message to stderr
 * @exit_code: the exit code to exit with
 * @message: the error message to print to stderr
 * @filename: the filename to include in the error message
 *
 * Return: void
 *
*/

void error_message(int exit_code, char *message, char *filename)
{
dprintf(STDERR_FILENO, message, filename);
exit(exit_code);
};

/**
 * main- copies the content of a file to another
 * @argc: the number of arguments passed to the program
 * @argv: an array of the arguments passed to the program
 *
 * Return: 0 on success, 97,98,99, or 100 on failure
*/

int main(int argc, char **argv)
{
int file_from, file_to, bytes_written;
char *buffer[BUFFER_SIZE];
mode_t permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

if (argc != 3)
error_message(97, "Usage: cp file_from file_to\n", NULL);

file_from = open(argv[1], O_RDONLY);
if (file_from == -1)
error_message(98, "Error: Can't read from file %s\n", arg[1]);

file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, permissions);
if (file_to == -1)
error_message(99, "Error: Can't write to %s\n", argv[2]);

while ((bytes_read = read(file_from, buffer, BUFFER_SIZE)) > 0)
{
bytes_written = write(file_to, buffer, bytes_read);
if (bytes_written == -1)
error_message(99, "Error: Can't write to %s\n", argv[2]);
if (bytes_written != bytes_read)
error_message(99, "Error: Write to %s incomplete\n", argv[2]);
}

if (bytes_read == -1)
error_message(98, "Error: Can't read from file %s\n", argv[1]);

if (close(file_from) == -1)
error_message(100, "Error: Can't close fd %d\n", file_from);
if (close(file_to) == -1)
error_message(100, "Error: Can't close fd %d\n", file_to);

return (0);
}
