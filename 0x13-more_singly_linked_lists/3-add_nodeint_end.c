#include "lists.h"
/**
 **add_nodeint_end- adds a new node at the end of the linked list
 *@n: number
 *Return: new node
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new_node, *current;

new_node = malloc(sizeof(listint_t)); /*allocate memory for new node*/

if (new_node == NULL)
return (NULL);

new_node->n = n;
new_node->next = NULL;

if (*head == NULL)
{
*head = new_node;
}
else
{
current = *head;
while (current->next != NULL)
{
current = current->next;
}
current->next = new_node;
}
return (new_node);

}
