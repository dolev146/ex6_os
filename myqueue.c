#include "myqueue.h"
#include <stdlib.h>
#include <stdio.h>

node_t *head = NULL;
node_t *tail = NULL;

void enQ(void *element)
{
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    newnode->element = element;
    newnode->next = NULL;
    if (tail == NULL)
    {
        head = newnode;
    }
    else
    {
        tail->next = newnode;
    }
    tail = newnode;
}

// return the pointer to a client_socket
void *deQ()
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        void *result = head->element;
        node_t *temp = head;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        free(temp);
        return result;
    }
}
