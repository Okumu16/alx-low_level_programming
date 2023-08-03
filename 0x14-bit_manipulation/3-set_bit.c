#include "main.h"
/**
 * set_bit - a function that sets the value of a bit to 1 at an index
 * @n: number to be set
 * @index: position of n
 * Return: 1 if works and -1 if an error occurred
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	*n |= 1UL << index;
	return (1);
}
