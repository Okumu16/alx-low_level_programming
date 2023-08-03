#include "main.h"
/**
 * binary_to_uint - a function that converts a binary to an unsigned int
 * Return: converted number
 * @b: the binary number
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	
	if (b == NULL)
		return (0);
	while (*b)
	{
		if (*b == '0')
		{
			result = result << 1;
		}
		else if (*b == '1')
		{
			result = (result << 1) | 1;
		}
		else
		{
			return (0);
		}
		b++;
	}
	return (result);
}
