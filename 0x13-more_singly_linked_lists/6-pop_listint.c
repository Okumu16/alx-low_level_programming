#include "lists.h"
/**
 * pop_listint - deletes the head of the node
 * @head: a double pointer
 *Return: empty
 */
int pop_listint(listint_t **head)
{

	listint_t *doll;
	int n;

	if (head == NULL || *head == NULL)
		return (0);
	doll = *head;
	*head = doll->next;
	n = doll->n;
	free(doll);
	return (n);
}
