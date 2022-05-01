#include "myqueue.h"
#include <stdlib.h>
#include <stdio.h>

node_t *head = NULL;
node_t *tail = NULL;

void NcreateQ(){
    if(head != NULL){
        printf("Queue already exists\n");
        return;
    }
    head = NULL;
    tail = NULL;
}

void NdestroyQ(){
    if(head == NULL){
        printf("Queue does not exist\n");
        return;
    }
    node_t *temp = head;
    while(temp != NULL){
        head = head->next;
        free(temp);
        temp = head;
    }
    head = NULL;
    tail = NULL;
}

void NenQ(void *element)
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

// return the pointer to a tail node
void* NdeQ()
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
