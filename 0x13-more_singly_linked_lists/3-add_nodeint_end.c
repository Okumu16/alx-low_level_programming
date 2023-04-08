#include "lists.h"

/**
 * add_nodeint_end - add a new node at the end of a listint_t list
 * @head: pointer to the pointer the first node
 * @n: the data to be stored in the node
 *
 * Return: a pointer to the pointer to the first node
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	/* aux is a pointer I use for moving to the tail of the list*/
	listint_t *new, *x;

	new = malloc(sizeof(listint_t));
	if (!new)
	{
		return (NULL);
	}
	new->n = n;

	if (*head)
	{
		x = *head;
		while (x->next)
			x = aux->next;
		aux->next = new;
	}
	else
	{
		*head = new;
	}
	return (*head);
}
