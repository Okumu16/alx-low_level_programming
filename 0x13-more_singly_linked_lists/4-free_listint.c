#include "lists.h"


/**
 * free_listint - Frees a linked list.
 * @head: pointer to the first node.
 **/

void free_listint(listint_t *head)
{
listint_t *current;

while (current != NULL)
{
current = head;
head = head->next;
free(current);
}
}
