#ifndef MYQUEUE_H_
#define MYQUEUE_H_
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct node
{
    struct node *next;
    void *element;
} node, *pnode;

typedef struct myqueue_t
{
    pthread_mutex_t queue_mutex;
    pthread_cond_t condition_var;
    pnode head;
    pnode tail;
} myqueue_t, *pmyqueue_t;

typedef struct node node_t;
void NenQ(void *element, pmyqueue_t queue);
void *NdeQ(pmyqueue_t queue);
pmyqueue_t NcreateQ();
void NdestroyQ(pmyqueue_t);

#endif // MYQUEUE_H_