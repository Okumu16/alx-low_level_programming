#include "lists.h"

/**
 * print_listint- prints all members of the node
 * @h: head of the pointer
 * returns-the number of nodes
*/
size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}
	return (count);
}
