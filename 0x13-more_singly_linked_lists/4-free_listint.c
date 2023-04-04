#include "lists.h"


/**
 * free_listint - Frees a linked list.
 * @head: pointer to the first node.
 **/

void free_listint(listint_t *head)
{
	listint_t *ptr, *temp;
	ptr = head;
	
	while (ptr != NULL)
	{
		temp = ptr->next;
		free(ptr);
		ptr = temp;
		
	}
}
