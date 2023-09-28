#include "main.h"
/**
 * clear_bit- sets value of a bit to 0 at an index
 * @n: value of bits at an index
 * @index: position of a bit
 * Return: 1 if worked or -1 if an error
*/
int clear_bit(unsigned long int *n, unsigned int index)
{
if (index >= sizeof(unsigned long int) * 8)
{
return (-1);
}
*n &= ~(1UL << index);
return (1);
}
