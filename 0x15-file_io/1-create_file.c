#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "main.h"

/**
 * create_file- creates file
 * @filename: name of the file to create
 * @text_content: Null terminated string
 * Return: 1 on success
 * -1 on failure
*/
int create_file(const char *filename, char *text_content)
{int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

if (filename == NULL)
return (-1);


if (fd == -1)
return (-1);

if (text_content != NULL)
{
int len = strlen(text_content);

if (write(fd, text_content, len) != len)
{
close(fd);
return (-1);
}
}
close(fd);
return (1);
}
