#include "lists.h"

/**
 * find_listint_loop - finds the loop in a singly linked list.
 * @head: pointer to the head of the linked list.
 * Return: address of the node where the loop is starting or NULL if there's no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *dog, *bear;

	dog = bear = head;
	while (dog && bear && bear->next)
	{
		dog = dog->next;
		bear = bear->next->next;
		if (dog == bear)
		{
			dog = head;
			break;
		}
	}
	if (!dog || !bear || !bear->next)
		return (NULL);
	while (dog != bear)
	{
		dog = bear->next;
		bear = bear->next;
	}
	return (bear);
}
