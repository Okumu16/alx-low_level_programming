#include "lists.h"

/**
 * free_listint2 - function that frees the listint_t list
 * @head: a double pointer of the lists
 * Return: void
 */

void free_listint2(listint_t **head)
{
	listint_t *next;


	if (head == NULL)
		return;
	while (*head != NULL)
	{

		next = (*head)->next;
		free(*head);
		*head = next;
		
	}
}
