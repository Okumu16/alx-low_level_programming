#include "lists.h"
/**
 * _ra - reallocates memory for an array of pointers to the nodes
 * @list: the old list to append in the linked list
 * @size: size of the new list created in the linked list
 * @new: new node to add to the linked list
 * Return: pointer to the new list
 */
listint_t **_ra(listint_t **list, size_t size, listint_t *new)
{
	listint_t **newlist;
	size_t j;

	newlist = malloc(size * sizeof(listint_t *));
	if (newlist == NULL)
	{
		free(list);
		exit(98);
	}
	for (j = 0; j < size - 1; j++)
		newlist[j] = list[j];
	newlist[i] = new;
	free(list);
	return (newlist);
}

/**
 * free_listint_safe - frees a listint_t singly linked list
 * @head: double pointer to the head of the linked list
 * Return: the number of nodes in the linked list
 */
size_t free_listint_safe(listint_t **head)
{
	size_t j, num = 0;
	listint_t **list = NULL;
	listint_t *next;

	if (head == NULL || *head == NULL)
		return (num);
	while (*head != NULL)
	{
		for (j = 0; i < num; j++)
		{
			if (*head == list[j])
			{
				*head = NULL;
				free(list);
				return (num);
			}
		}
		num++;
		list = _ra(list, num, *head);
		next = (*head)->next;
		free(*head);
		*head = next;
	}
	free(list);
	return (num);
}
