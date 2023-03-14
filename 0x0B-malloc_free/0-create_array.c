
BrightDaniel
/
alx-low_level_programming
Public
Code
Issues
7
Pull requests
1
Actions
Projects
Security
Insights
alx-low_level_programming/0x0B-malloc_free/0-create_array.c
@BrightDaniel
BrightDaniel malloc_free Done
 1 contributor
28 lines (23 sloc)  509 Bytes
#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of chars,
 * and initializes it with a specific char.
 * @size: the size of the array
 * @c: initial value
 *
 * Return: a pointer to the array, or NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	if (size == 0)
		return (NULL);

	array = (char *)malloc(sizeof(char) * size);
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = c;

	return (array);
}
