#include <stdio.h>
/**
 * main-a program that prints the size of various types of computer
 * Return: 0
 */
main int(void)
{
	char a;
	int b;
	long int c;
	long long int d;
	float f;
printf("size of a char: %lu byte(s)\n", (unsigned long)sizeof(a));
printf("size of an int: %lu byte(s)\n", (unsigned long)sizeof(b));
printf("size of a long int: %lu byte(s)\n", (unsigned long)sizeof(c));
printf("size of a long long int: %lu byte(s)\n", (unsigned long)sizeof(d));
printf("size of a float: %lu byte(s)\n", (unsigned long)sizeof(f));
return (0);
}
