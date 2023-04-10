#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void check_num_args(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

void check_file_read(ssize_t check, char *file_name, int fd_source, int fd_destination)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_name);
		if (fd_source != -1)
			close(fd_source);
		if (fd_destination != -1)
			close(fd_destination);
		exit(98);
	}
}

void check_file_write(ssize_t check, char *file_name, int fd_source, int fd_destination)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", file_name);
		if (fd_source != -1)
			close(fd_source);
		if (fd_destination != -1)
			close(fd_destination);
		exit(99);
	}
}

void check_fd_close(int check, int fd)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", fd);
		exit(100);
	}
}

int main(int argc, char *argv[])
{
	int source_file_descriptor, destination_file_descriptor, close_destination_fd, close_source_fd;
	ssize_t bytes_read, bytes_written;
	char buffer[1024];
	mode_t file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	check_num_args(argc);

	source_file_descriptor = open(argv[1], O_RDONLY);
	check_file_read((ssize_t)source_file_descriptor, argv[1], -1, -1);

	destination_file_descriptor = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
	check_file_write((ssize_t)destination_file_descriptor, argv[2], source_file_descriptor, -1);

	bytes_read = 1024;

	while (bytes_read == 1024)
	{
		bytes_read = read(source_file_descriptor, buffer, 1024);
		check_file_read(bytes_read, argv[1], source_file_descriptor, destination_file_descriptor);

		bytes_written = write(destination_file_descriptor, buffer, bytes_read);
		if (bytes_written != bytes_read)
			bytes_written = -1;

		check_file_write(bytes_written, argv[2],
