#include "blockqueue.h"
#include "myqueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;
pthread_mutex_t queueu_mutex = PTHREAD_MUTEX_INITIALIZER;

void *enQ(void *args)
{
    pthread_mutex_lock(&queueu_mutex);
    NenQ(element);
    printf("enQ: %d\n", *(int *)element);
    pthread_mutex_unlock(&queueu_mutex);
    // dont know what to choose broadcat or signal
    pthread_cond_broadcast(&condition_var);
    return NULL;
}

void *deQ(void *args)
{
    pthread_mutex_lock(&queueu_mutex);
    void *pointer;
    while ((pointer = NdeQ()) == NULL)
    {
        printf("deQ: waiting\n");
        pthread_cond_wait(&condition_var, &queueu_mutex);
    }
    printf("deQ: %d\n", *(int *)pointer);
    pthread_mutex_unlock(&queueu_mutex);
    return pointer;
}

pmyqueue_t createQ()
{
    pthread_mutex_lock(&queueu_mutex);
    pmyqueue_t result = NcreateQ();
    printf("createQ\n");
    pthread_mutex_unlock(&queueu_mutex);
    return result;
}
void destroyQ()
{
    pthread_mutex_lock(&queueu_mutex);
    NdestroyQ();
    printf("destroyQ\n");
    pthread_mutex_unlock(&queueu_mutex);
}