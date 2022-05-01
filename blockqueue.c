#include "blockqueue.h"
#include "myqueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;
pthread_mutex_t queueu_mutex = PTHREAD_MUTEX_INITIALIZER;

void *enQ(void *element)
{
    pthread_mutex_lock(&queueu_mutex);
    NenQ(element);
    printf("enQ: %d\n", *(int *)element);
    pthread_mutex_unlock(&queueu_mutex);
    pthread_cond_signal(&condition_var);
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

void createQ()
{
    pthread_mutex_lock(&queueu_mutex);
    NcreateQ();
    printf("createQ\n");
    pthread_mutex_unlock(&queueu_mutex);
}
void destroyQ()
{
    pthread_mutex_lock(&queueu_mutex);
    NdestroyQ();
    printf("destroyQ\n");
    pthread_mutex_unlock(&queueu_mutex);
}