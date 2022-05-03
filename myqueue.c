#include "myqueue.h"
#include <stdlib.h>
#include <stdio.h>

pmyqueue_t NcreateQ()
{
    pmyqueue_t queue = (pmyqueue_t)malloc(sizeof(myqueue_t));
    queue->head = NULL;
    queue->tail = NULL;
    // pthread init cond
    pthread_mutex_init(&queue->queue_mutex, NULL);
    pthread_cond_init(&queue->condition_var, NULL);
    return queue;
}

void NdestroyQ(pmyqueue_t queue)
{

    if (queue->head == NULL)
    {
        printf("Queue does not exist\n");
        return;
    }
    pthread_mutex_destroy(&queue->queue_mutex);
    pthread_cond_destroy(&queue->condition_var);
    // free all the elements of the queue with while loop
    while (queue->head != NULL)
    {
        pnode temp = queue->head;
        queue->head = queue->head->next;
        free(temp);
    }
    // dont know if we really need to free the queue itself or not co-pilot added this
    // TODO check if i need this
    // TODO
    free(queue);
}

void NenQ(void *element, pmyqueue_t queue)
{
    pnode new_node = (pnode)malloc(sizeof(node_t));
    new_node->element = element;
    new_node->next = NULL;
    if (queue->head == NULL)
    {
        queue->head = new_node;
        queue->tail = new_node;
    }
    else
    {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
}

// return the pointer to a tail node
void *NdeQ(pmyqueue_t queue)
{
    if (queue->head == NULL)
    {
        printf("Queue is empty\n");
        return NULL;
    }
    pnode temp = queue->head;
    queue->head = queue->head->next;
    if (queue->head == NULL)
    {
        queue->tail = NULL;
    }
    return temp->element;
    // TODO need to check if i need to free temp or not
}

// {
//     if (head == NULL)
//     {
//         return NULL;
//     }
//     else
//     {
//         void *result = head->element;
//         node_t *temp = head;
//         head = head->next;
//         if (head == NULL)
//         {
//             tail = NULL;
//         }
//         free(temp);
//         return result;
//     }
// }
