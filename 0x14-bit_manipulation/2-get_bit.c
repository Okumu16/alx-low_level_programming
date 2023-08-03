#include "main.h"
/**
 * get_bit - a function that gets the value of a bit at a given index
 * @n: value of the bit
 * @index: position of the number
 * Return: 0 always
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	return ((n >> index) & 1);
}
