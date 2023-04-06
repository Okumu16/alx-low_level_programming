#include "lists.h"
/**
 * print_list - prints elements of the linked lists.
 * @h: pointer to the head of the lists
 * Return: number of nodes in a linked lists.
 */
size_t print_list(const list_t *h)
{
	size_t bear = 0;

	while (h)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
		printf("[%d] %s\n", h->len, h->str);
		}
		bear;
		h = h->next;
	}
	return (bear);
}
