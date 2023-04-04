#include "lists.h"

listint_t *add_nodeint_end(listint_t **head, const int n)
{

    listint_t *ptr, *node;

    node = (listint_t *)malloc(sizeof(listint_t));
    if (node == NULL)
    {
        return (NULL);
    }
    node->n = n;
    ptr = *head;

    if (ptr == NULL)
    {
        *head = node;
    }
    else
    {
        while (ptr->next != NULL)
        {
            /*printf("ptr:  %p\nhead: %p\n", (void *)ptr, (void *)*head);*/
            ptr = ptr->next;
        }
        ptr->next = node;
    }
    return (*head);
}