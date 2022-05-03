#include "blockqueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t wrapper_mutex = PTHREAD_MUTEX_INITIALIZER;

void *enQ(void *arguments)
{
    struct parameters *args = (struct parameters *)arguments;
    pmyqueue_t queue = args->queue;
    void *element = args->element;
    pthread_mutex_lock(&queue->queue_mutex);
    NenQ(element, queue);
    printf("enQ: %d queue adress %p \n", *(int *)element, queue);
    pthread_mutex_unlock(&queue->queue_mutex);
    // dont know what to choose broadcat or signal
    pthread_cond_broadcast(&queue->condition_var);
    return NULL;
}

void *deQ(void *arguments)
{
    struct parameters *args = (struct parameters *)arguments;
    pmyqueue_t queue = args->queue;
    void *element = args->element;
    pthread_mutex_lock(&queue->queue_mutex);
    void *pointer;
    while ((pointer = NdeQ(queue)) == NULL)
    {

        printf("deQ: waiting , queue number %p \n", queue);
        pthread_cond_wait(&queue->condition_var, &queue->queue_mutex);
    }
    printf("deQ: %d , queue number %p \n", *(int *)pointer, queue);
    element = pointer;
    pthread_mutex_unlock(&queue->queue_mutex);
    return pointer;
}

pmyqueue_t createQ()
{
    pthread_mutex_lock(&wrapper_mutex);
    pmyqueue_t result = NcreateQ();
    printf("createQ %p \n", result);
    pthread_mutex_unlock(&wrapper_mutex);
    return result;
}
void destroyQ(pmyqueue_t queue)
{
    pthread_mutex_lock(&wrapper_mutex);
    printf("destroyQ %p\n", queue);
    NdestroyQ(queue);
    pthread_mutex_unlock(&wrapper_mutex);
}