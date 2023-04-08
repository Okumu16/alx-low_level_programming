#include "lists.h"

/**
 * print_listint- prints all members of the linked list node.
 * @h: pointer to the head of the linked list
 * returns-the number of nodes
*/
size_t print_listint(const listint_t *h)
{
	size_t number = 0;

	while (h != NULL)
	{
		
		printf("%d\n", h->n);
		h = h->next;
		number++;
	}
	return (number);
}
