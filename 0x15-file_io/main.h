#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>



int _putchar(char c);
int create_file(const char *filename, char *text_content);
ssize_t read_textfile(const char *filename, size_t letters);









#endif
